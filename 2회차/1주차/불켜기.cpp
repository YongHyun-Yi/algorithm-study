// 백준 11967번 문제

#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
#define LIGHT first
#define VISIT second

using namespace std;

int n, m;
pair<bool, bool> room[101][101]; // x - 불 y - 방문

vector<pair<int, int>> swtich_list[101][101];
queue<pair<int, int>> check_que;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
	room[1][1] = {true, true};
	check_que.push({1, 1});

	while (check_que.size())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (auto target : swtich_list[select.X][select.Y])
		{
			// 이렇게 받아오면 while문으로 사이즈를 체크하거나 front를 뽑아내고 pop을 하지 않아도
			// 알아서 있는만큼 하나씩 받아온다... 이 표현식도 기억해둘것

			if (room[target.X][target.Y].LIGHT) continue;
				// 방문했다는것은 이미 스위치가 켜져있다는 뜻이니 skip 한다
				//
				// 원본은 bfs함수 맨 위에서 현재 좌표의 visit을 true 해주기때문에
				// 가능했으나 나는 밑에서 queue에 추가할때 미리 true로 해주므로
				// if (room[target.X][target.Y].VISIT) 에는 무조건적으로 걸릴수밖에 없어서
				// 불을 한번이라도 켰는가?를 체크하기위해 .LIGHT로 수정함
			
			room[target.X][target.Y].LIGHT = true;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = target.X + dx[dir];
				int ny = target.Y + dy[dir];

				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

				if (room[nx][ny].VISIT)
				{
					room[target.X][target.Y].VISIT = true;
					check_que.push({target.X, target.Y});
					break;
				}
			}
				// << 다른사람 코드보고 배운것 >>
				//
				// 계산속도를 줄이는 방법
				// bfs를 여러번 도는게 아니라 bfs의 시작지점을 조건부로 주가한다
				//
				// 불을 켜더라도 연결된 지역이 없으면 즉 그 방까지 갈수없으면 거기서 종료
				// 하지만 인근에 방문한 지역이 있으면 그곳에 불이 켜져있고
				// 불이 켜져있으면 연결되어서 이동할수있다
				//
				// 즉 하던대로 visit을 초기화하고 bfs를 또 돌리면 어차피 도착하게 될 곳이니
				// visit을 초기화하고 또 bfs를 수행하는것보단 거기서 바로 출발하는게 가능
				// 그곳을 bfs의 시작지점으로 조건부로 추가할수있다
				//
				// 수정한것
				// 원본코드와 visit을 true로 설정하는 타이밍이 다르다
				// 나는 queue에 추가할때 미리 체크하기때문에 수정하니 통과되었음
				// 단순히 불만 켤때와, 불켠방이 시작점으로 추가될때를 분리해서 생각해야함
				// 그리고 시작점으로 추가된다는건 곧 그곳을 방문했고 그곳을 기점삼아 탐색을 시작한다는 의미
				// 그러니 여기서도 queue에 추가할때 visit을 true로 설정해줘야한다
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 1 || nx > n || ny < 1 || ny > n || !room[nx][ny].LIGHT || room[nx][ny].VISIT) continue;

			room[nx][ny].VISIT = true;
			check_que.push({nx, ny});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c >> d;
		swtich_list[a][b].push_back({c, d});
	}

	room[1][1].LIGHT = true;

	bfs();

	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			result += room[i][j].LIGHT;
	cout << result;
}
/*
	한 방이 켤수있는 다른방의 스위치는 여러개 들어올수있음, 계획수정
	1. 우선 queue에서 front를 뽑아낸다
	2. front가 켤수있는 불을 다 켠다, 불켠횟수 +1씩 해주기
	3. nx ny 검사, 범위 안에있고 불이켜져있으면 queue에 push
	--------------------------------------------------------------
	또 계획수정
	그냥 입력받은걸 tuple<int, int, int, int>로 받아서 정렬
	tuple에서 하나 뽑아서 현재위치와 비교후 같으면 room으로 불 켜기, (room[nx][ny] == false) 이여야함
	불이 켜져있으면 bfs에서 이동할수있는 영역이 더 넓어진 상태가됨
	bfs 쭉 돌림(빈 땅인경우 push)
	또 현재위치랑 tuple위치랑 비교해서 불키고 bfs돌리고 반복

	즉
	0. visit 초기화
	1. bfs돌림
	2. 현재위치 비교
	3. 현재위치에서 켤수잇는 불 켜기 (room 배열의 bool 변수 변경) (이미 켜져잇으면 카운트하지 않음)
	4. 다시 1번부터
	--------------------------------------------------------------
	또 또 계획 수정...
	tuple로 입력받아서 sort하려고 했으나
	새로 불이켜져서 갈수잇는 방들이 항상 tuple의 sort정렬순은 아님...

	1 1 1 2
	1 1 1 3
	1 2 2 1
	1 2 3 1
	1 3 2 2
	1 3 2 3

	1 4 3 3
	1 4 3 5

	2 1 1 4

	위의 예제에서 (1, 4) 를 가려면 (2, 1) 에서 스위치를 켜야하나
	(2, 1)에 스위치가 켜져있어서 이동할수는 있어도 tuple의 front가 (1, 4)로 되어있기 때문에
	(2, 1)에서 켤수있는 스위치를 켤수없음
	그냥 vector로 받아서 push로 넣는식으로하고
	방에 입장하면 그 즉시 해당좌표로 vector에 접근해서 스위치 모두 켜버리는식으로 하면
	정렬에 상관없이 항상 스위치를 켤수있음
*/