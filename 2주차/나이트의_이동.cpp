// 백준 7562번 문제

#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second
	// 순서 헛갈리지 말것...

using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int dis[300][300];
		for (int i = 0; i < 300; i++)
			fill(dis[i], dis[i] + 300, -1);
		
		int size, x, y;
		cin >> size >> x >> y; // 시작지점
		dis[x][y] = 0;

		queue<pair<int, int>> check_que;
		check_que.push({x, y});

		cin >> x >> y; // 목표지점
		while (dis[x][y] == -1)
		{
			pair<int, int> select = check_que.front();
			check_que.pop();

			for (int dir = 0; dir < 8; dir++)
			{
				int nx = select.X + dx[dir];
				int ny = select.Y + dy[dir];

				if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
				if (dis[nx][ny] != -1) continue;

				dis[nx][ny] = dis[select.X][select.Y] + 1;
				check_que.push({nx, ny});
			}
		}
		cout << dis[x][y] << '\n';
	}
}