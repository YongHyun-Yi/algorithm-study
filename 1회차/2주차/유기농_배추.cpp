// 백준 1012번 문제

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int m, n, k, board[50][50], visit[50][50];
		for (int i = 0; i < 50; i++)
		{
			fill(board[i], board[i] + 50, 0);
			fill(visit[i], visit[i] + 50, 0);
		}
		cin >> m >> n >> k;
		while (k--)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int count = 0;
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		queue<pair<int, int>> check_que;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] && !visit[i][j])
				{
					count++;
					visit[i][j] = 1;
					check_que.push({i, j});
				}

				while (!check_que.empty())
				{
					pair<int, int> select = check_que.front();
					check_que.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = select.first + dx[dir];
						int ny = select.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (!board[nx][ny] || visit[nx][ny]) continue;

						visit[nx][ny] = 1;
						check_que.push({nx, ny});
					}
				}
			}
		}
		cout << count << '\n';
		// cout << "answer : " << count << '\n';
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 		cout << board[i][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "---------------------\n";
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 		cout << visit[i][j] << " ";
		// 	cout << "\n";
		// }
	}
}