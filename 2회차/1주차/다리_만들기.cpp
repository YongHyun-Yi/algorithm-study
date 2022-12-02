// 백준 2146번 문제

#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, mn = 10000;
int board[100][100];
int bridge[100][100];
bool visit[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(pair<int, int> start_pos)
{
	// 섬을 돌면서 해당 섬의 visit을 먼저채우고
	// 섬의 외곽을 queue에 추가
	// 그상태로 bfs 수행하여 visit이 체크안된 섬에 도달하면 bridge 길이 갱신

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			bridge[i][j] = 0;
				// 이번 분기에서 건설해볼 다리들 초기화

	queue<pair<int, int>> island_check;
	queue<pair<int, int>> bridge_que;
	visit[start_pos.X][start_pos.Y] = true;
	island_check.push(start_pos);
	
	while (island_check.size())
	{
		pair<int, int> select = island_check.front();
		island_check.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny]) continue;

			if (board[nx][ny])
			{
				visit[nx][ny] = true;
				island_check.push({nx, ny});
			}
			else
			{
				bridge[nx][ny] = 1;
				bridge_que.push({nx, ny});
			}
		}
	}
	
	while (bridge_que.size())
	{
		pair<int, int> select = bridge_que.front();
		bridge_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] || bridge[nx][ny]) continue;

			if (board[nx][ny]) // visit 체크가 안된 육지에 도착
			{
				mn = min(mn, bridge[select.X][select.Y]);
				return ;
			}
			else // 여전히 바다
			{
				bridge[nx][ny] = bridge[select.X][select.Y] + 1;
				bridge_que.push({nx, ny});
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] || !board[i][j]) continue;
				// 바다거나 이전 bfs에서 해당 섬에 다리를 건설해봤으면 pass
			
			bfs({i, j});
		}
	}

	cout << mn;
}