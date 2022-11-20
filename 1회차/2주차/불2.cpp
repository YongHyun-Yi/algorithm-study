// 백준 5427번 문제

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

char board[1000][1000];
int s_dis[1000][1000], f_dis[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		queue<pair<int, int>> s_que, f_que;

		for (int i = 0; i < 1000; i++)
		{
			fill(board[i], board[i] + 1000, 0);
			fill(s_dis[i], s_dis[i] + 1000, -1);
			fill(f_dis[i], f_dis[i] + 1000, -1);
		}

		int width, height;
		cin >> width >> height;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '@')
				{
					s_dis[i][j] = 0;
					s_que.push({i, j});
				}
				else if (board[i][j] == '*')
				{
					f_dis[i][j] = 0;
					f_que.push({i, j});
				}
			}
		}

		while (!f_que.empty())
		{
			pair<int, int> select = f_que.front();
			f_que.pop();

			for (int dir = 0; dir < 4; dir ++)
			{
				int nx = select.X + dx[dir];
				int ny = select.Y + dy[dir];

				if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
				if (board[nx][ny] == '#' || f_dis[nx][ny] >= 0) continue;

				f_dis[nx][ny] = f_dis[select.X][select.Y] + 1;
				f_que.push({nx, ny});
			}
		}

		int result = 0;
		while (!s_que.empty() && !result) // while 조건문에 !result를 추가해야함, 답을 찾았어도 break는 for문을 깨지만 while문은 깨지않았기때문에 다음 탐색의 답이 덮어짐, 벽이 하나도 없는 케이스를 생각하면됨
		{
			pair<int, int> select = s_que.front();
			s_que.pop();

			for (int dir = 0; dir < 4; dir ++)
			{
				int nx = select.X + dx[dir];
				int ny = select.Y + dy[dir];

				if (nx < 0 || nx >= height || ny < 0 || ny >= width)
				{
					result = s_dis[select.X][select.Y] + 1;
					break;
				}
				if (board[nx][ny] == '#' || s_dis[nx][ny] >= 0) continue;
				if (f_dis[nx][ny] != -1 && f_dis[nx][ny] <= s_dis[select.X][select.Y] + 1) continue;

				s_dis[nx][ny] = s_dis[select.X][select.Y] + 1;
				s_que.push({nx, ny});
			}
		}
		if (result) cout << result << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}