// 백준 2206번 문제

#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[1000][1000];
int dis[1000][1000];
queue<pair<int, int>> check_que;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < n; i++)
		fill(dis[i], dis[i] + m, -1);
	
	dis[0][0] = 0;
	check_que.push({0, 0});

	while (!check_que.empty())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx >= n && ny >= m) cout << dis[select.X][select.Y] + 1;
			if (nx < 0 || ny < 0 || dis[nx][ny] >= 0) continue;
		}
	}
}