// 백준 15683번 문제

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define X first
#define Y second

using namespace std;

int n, m;
int office[8][8];
int board[8][8];
vector<pair<int, int>> cctv;

vector<pair<int, int>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// vector<pair<int, int>> cctv_1 = {{1, 0}};
// vector<pair<int, int>> cctv_2 = {{-1, 0}, {1, 0}};
// vector<pair<int, int>> cctv_3 = {{0, -1}, {1, 0}};
// vector<pair<int, int>> cctv_4 = {{-1, 0}, {0, -1}, {1, 0}};
// vector<pair<int, int>> cctv_5 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	// 카메라가 바라보는 방향을 전부 정해주기보다는
	// 카메라별로 dxy에서 몇번째 요소들을 사용할지를 정하는게 더 효과적

void check_area(int dir, int x, int y)
{
	dir %= 4;
	while(1)
	{
		x += dxy[dir].X;
		y += dxy[dir].Y;

		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) break; // 범위 밖이거나 벽이면 중지
		if (board[x][y] != 0) continue; // 이미 방문한곳 말고도 카메라가 있는 경우도 포함해서

		board[x][y] = 7; // 방문 표시
	}
}

int check_cctv(int temp)
{
	for (int k = 0; k < cctv.size(); k++) // cctv마다 모든 방향을 체크하는게 아니라 / 4진수 4자리로 변환가능한 수를 for 루프로 돌면서 카메라에 순서대로 하나씩 넣어준다...
		{
			int dir = temp % 4; // 4진수로 변환, 각 카메라마다 한자리수씩 나눠준다
			temp /= 4; // 몫을 남겨둬야 다음 카메라에 넣어줄 % 연산이 가능해진다
			switch (board[cctv[k].X][cctv[k].Y])
			{
				case 1:
					check_area(dir, cctv[k].X, cctv[k].Y);
					break;
				
				case 2:
					check_area(dir, cctv[k].X, cctv[k].Y);
					check_area(dir + 2, cctv[k].X, cctv[k].Y);
					break;
				
				case 3:
					check_area(dir, cctv[k].X, cctv[k].Y);
					check_area(dir + 1, cctv[k].X, cctv[k].Y);
					break;
				
				case 4:
					check_area(dir, cctv[k].X, cctv[k].Y);
					check_area(dir + 1, cctv[k].X, cctv[k].Y);
					check_area(dir + 2, cctv[k].X, cctv[k].Y);
					break;
				
				case 5:
					check_area(dir, cctv[k].X, cctv[k].Y);
					check_area(dir + 1, cctv[k].X, cctv[k].Y);
					check_area(dir + 2, cctv[k].X, cctv[k].Y);
					check_area(dir + 3, cctv[k].X, cctv[k].Y);
					break; // 방향도 반복문을 넣어줘야함
			}
		}
	
	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += (board[i][j] == 0); // 이런식으로도 더할수있구나

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int min_area = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6) cctv.push_back({i, j});
			if (office[i][j] == 0) min_area++; // 카메라가 0개일때를 생각해서 처음 0의 개수를 저장
		}
	}
	
	for (int temp = 0; temp < pow(4, cctv.size()); temp++)
	{
		copy(&office[0][0], &office[0][0] + 8 * 8, &board[0][0]); // 2차원배열 이상부터는 인자가 다름

		min_area = min(min_area, check_cctv(temp));
	}

	cout << min_area;
}

// 불! 처럼 시작점을 여러개로 bfs를 돌리는줄 알았으나 아니였음...
// 탐색은 카메라가 볼수있는 방향을 한 회차마다 다 돌아보는식 보다는
// 한쪽방향을 탐색불가능할때까지 쭉 탐색하도록 하는것
// 더 직관적이고 쉬우나 백트래킹, 재귀랑 무슨 상관이 있는지는 모르겠음...
// for 반복문을 사용해서 경우의 수를 4^카메라의 수로 구현함
// 각 숫자는 카메라가 회전한 경우의 수 (0 - 정방향 1 - 한 번 회전 ....)
// 경우의 수를 카메라마다 % 4로 받음, 다음 카메라를 위해서 경우의 수는 /= 4를 연산
// 4방향이니까 4로 받아서 dxy에서 인덱스로 사용
// 다른 방향도 함께 탐색할때는 변수에 +1 +2 ... 연산을 해줄때 4를 넘어버릴수있는데
// 탐색 함수에서 dir % 4 를 한 번더 연산해줌
//
// 탐색때마다 배열을 인자로 넘겨주면 이렇게 구현안해도될것같음
// 배열을 전역변수로 사용하고있기때문에 dfs 백트래킹이 아니라 이렇게 하는건지??
// -----------------------------------------------------------------------------------------------------
// 1. 입력을 int 배열로
// 2. bfs의 시작점이 될 카메라를 vector에 추가
	// 0번째 카메라부터 재귀를 시작
	// 탈출조건 : depth == 카메라 vector의 사이즈 -> 사각지대의 수를 세서 변수에 최소값 비교후 대입
	// for 루프안에 방향을 넣고 각 방향마다 bfs함수를 실행, 다음 재귀(카메라 + 1, 처음방향)
// 4. bfs - 탐색할 nx ny좌표가 범위 밖이거나 6(벽)이면 continue
// 모든 방향을 한바퀴씩 돌면서 한 방향에서 벽을 만나거나 밖으로 나갈때까지 그 방향만 진행
// queue에 집어넣는게 아니라 해당 좌표를 계속 더해가면서 해당 칸을 체크
// ex) dxy = 1, 0 이면 이거 하나로 벽만나거나 밖으로 나갈때까지 쭉 체크
