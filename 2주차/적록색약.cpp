// 백준 10026번 문제

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string board[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	queue<pair<int, int>> check_que;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int r = 0, g = 0, b = 0, rg = 0;

	for (char c : "RGB")
	{
		bool visit[100][100];
		for (int i = 0; i < 100; i++)
			fill(visit[i], visit[i] + 100, 0);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == c && !visit[i][j])
				{
					visit[i][j] = 1;
					check_que.push({i, j});
					if (c == 'R')
						r++;
					else if (c == 'G')
						g++;
					else
						b++;
				}

				while (!check_que.empty())
				{
					pair<int, int> select = check_que.front();
					check_que.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = select.first + dx[dir];
						int ny = select.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != c || visit[nx][ny]) continue;

						visit[nx][ny] = 1;
						check_que.push({nx, ny});
					}
				}
			}
		}
	}

	bool visit[100][100];
	for (int i = 0; i < 100; i++)
		fill(visit[i], visit[i] + 100, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((board[i][j] == 'R' || board[i][j] == 'G') && !visit[i][j])
			{
				visit[i][j] = 1;
				check_que.push({i, j});
				rg++;
			}

			while (!check_que.empty())
			{
				pair<int, int> select = check_que.front();
				check_que.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = select.first + dx[dir];
					int ny = select.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if ((board[nx][ny] != 'R' && board[nx][ny] != 'G') || visit[nx][ny]) continue;

					visit[nx][ny] = 1;
					check_que.push({nx, ny});
				}
			}
		}
	}
	cout << r + g + b << " " << rg + b;
}