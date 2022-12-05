// 백준 16920번 문제

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m, p;
int move_mx[10], result[10];
char board[1000][1000];

queue<pair<int, int>> check_que[10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int current_player)
{
	int extend_pos = check_que[current_player].size(); // 현재 queue에 들어있는 좌표값 만큼만 진행, 즉 1회차씩만 진행한다
	for (int i = 0; i < extend_pos; i++)
	{
		pair<int, int> select = check_que[current_player].front();
		check_que[current_player].pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != '.') continue;

			board[nx][ny] = '0' + current_player;
			check_que[current_player].push({nx, ny});
			result[current_player]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; i++)
		cin >> move_mx[i];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= '1' && board[i][j] <= '9')
			{
				check_que[board[i][j] - '0'].push({i, j});
				result[board[i][j] - '0']++;
			}
		}
	}
	
	while (true)
	{
		int empty_player = 0;
		for (int i = 1; i <= p; i++) // 현재 영역을 확장할 플레이어
		{
			for (int j = 0; j < move_mx[i]; j++) // bfs를 호출하는 for문안에서 queue를 체크해줘야 한다, 이전 for문에서 미리 체크하면 queue가 비어있는채로 함수호출을 수백번을 해버리게된다... / 이게 시간초과의 원인이였음
			{
				if (check_que[i].empty())
				{
					empty_player++; // 해당 플레이어는 더이상 확장을 진행할수없다
					break; // 다음 for문 즉 다음 플레이어로 넘어간다
				}
				bfs(i);
			}
		}
		if (empty_player >= p) break; // queue가 비어있는 플레이어의 수가 전체 플레이어수 이상이면 종료, 처음에는 조건을 if (empty_player) 로 잡았는데 이러면 한명만 확장불가능해도 끝나버린다...
	}

	
	for (int i = 1; i <= p; i++)
		cout << result[i] << ' ';
}
