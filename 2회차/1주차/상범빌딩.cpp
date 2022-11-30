// 백준 6593번 문제

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char building[30][30][30];
int dis[30][30][30];

int l, r, c;
tuple<int, int, int> start_pos;
tuple<int, int, int> exit_pos;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs()
{
	queue<tuple<int, int, int>> check_que; // queue를 전역으로 선언하면 도중에 E에 도착해서 나갈때 아직 queue에 남아있는 요소가 있음...
	check_que.push(start_pos);

	while (check_que.size())
	{
		tuple<int, int, int> select = check_que.front();
		check_que.pop();

		int sel_x = get<0>(select);
		int sel_y = get<1>(select);
		int sel_z = get<2>(select);

		if (select == exit_pos)
		{
			cout << "Escaped in " << dis[sel_x][sel_y][sel_z] << " minute(s).\n"; // 출력에서 .이 빠졌음...
			return;
		}

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = sel_x + dx[dir];
			int ny = sel_y + dy[dir];
			int nz = sel_z + dz[dir];

			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c || dis[nx][ny][nz] > -1 || building[nx][ny][nz] == '#') continue;

			dis[nx][ny][nz] = dis[sel_x][sel_y][sel_z] + 1;
			check_que.push({nx, ny, nz});
		}
	}
	cout << "Trapped!\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> building[i][j][k];
					dis[i][j][k] = -1;

					if (building[i][j][k] == 'S')
					{
						start_pos = {i, j, k};
						dis[i][j][k] = 0;
					}
					else if (building[i][j][k] == 'E')
						exit_pos = {i, j, k};
				}
			}
		}

		bfs();
	}
}