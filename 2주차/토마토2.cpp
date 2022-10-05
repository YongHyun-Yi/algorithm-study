// 백준 7567번 문제

#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int board[100][100][100];
int dis[100][100][100];
queue<tuple<int, int, int>> check_que;
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};

// int dx[6] = {1, 0, -1, 0, 0, 0};
// int dy[6] = {0, 1, 0, -1, 0, 0};
// int dz[6] = {0, 0, 1, 0, -1, 0};
	// 순서를 모르겠음

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n, h;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) check_que.push({i, j, k});
				else if (board[i][j][k] == 0) dis[i][j][k] = -1;
					// 또 실수한 부분, (익은토마토 / 안익은 토마토, 비어있는 칸)으로 나누는게 아니라
					// (익은토마토, 비어있는칸 / 안익은 토마토) 이렇게 나눠야 영향받지 못한 토마토만 찾아낼수있음
					// 전자같이 나누면 비어있는 칸도 -1로 되어있어서 무조건 -1이 출력됨
					// 어차피 반복문에서는 0도 포함해서 continue하기때문에 비어있는칸은 피해가게 되어있음
			}
		}
	}

	// cout << "-------------------\n";
	// for (int i = 0; i < h; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		for (int k = 0; k < m; k++)
	// 		{
	// 			cout << dis[i][j][k] << " ";
	// 		}
	// 		cout << '\n';
	// 	}
	// 	cout << "-------------------\n";
	// }
	// cout << "-------------------\n";

	while (!check_que.empty())
	{
		tuple<int, int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nz = get<0>(select) + dz[dir];
			int nx = get<1>(select) + dx[dir];
			int ny = get<2>(select) + dy[dir];

			if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nz][nx][ny] == -1 || dis[nz][nx][ny] >= 0) continue;

			dis[nz][nx][ny] = dis[get<0>(select)][get<1>(select)][get<2>(select)] + 1;
			check_que.push({nz, nx, ny});
		}
	}

	int result = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dis[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				result = max(result, dis[i][j][k]);
			}
		}
	}

	cout << result;
}