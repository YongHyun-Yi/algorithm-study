// 백준 23563번 문제

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[500][500]; // 0 땅, 1 인접한땅, 2 벽
int dis[500][500];
pair<int, int> start_point;
pair<int, int> end_point;
int h, w;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> check_que;
queue<pair<int, int>> wall_que;

int wall_move_bfs(pair<int, int> select)
{
	while (wall_que.size())
	{
		pair<int, int> select = wall_que.front();
		wall_que.pop();

		if (select.X == end_point.X && select.Y == end_point.Y)
		{
			cout << dis[select.X][select.Y] << '\n';
			return 1;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w || dis[nx][ny] >= 0 || board[nx][ny] == 2) continue; // 보드판에서 벽인경우를 빠트렷음

			if (board[select.X][select.Y] == 1 && board[nx][ny] == 1)
			{
				dis[nx][ny] = dis[select.X][select.Y];
				wall_que.push({nx, ny});
			}
			else
			{
				dis[nx][ny] = dis[select.X][select.Y] + 1;
				check_que.push({nx, ny});
			}
		}
	}
	return 0;
}

void ground_move_bfs(pair<int, int> select)
{
	while (check_que.size())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		if (select.X == end_point.X && select.Y == end_point.Y)
		{
			cout << dis[select.X][select.Y] << '\n';
			return ;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w || dis[nx][ny] >= 0 || board[nx][ny] == 2) continue; // 보드판에서 벽인경우를 빠트렷음

			if (board[select.X][select.Y] == 1 && board[nx][ny] == 1)
			{
				dis[nx][ny] = dis[select.X][select.Y];
				wall_que.push({nx, ny});
				if (wall_move_bfs({nx, ny})) return ;
			}
			else
			{
				dis[nx][ny] = dis[select.X][select.Y] + 1;
				check_que.push({nx, ny});
			}
		}
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char c;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> c;
			if (c == '#')
			{
				board[i][j] = 2;
				if (i - 1 >= 0 && board[i - 1][j] != 2) board[i - 1][j] = 1;
				if (i + 1 < h && board[i + 1][j] != 2) board[i + 1][j] = 1;
				if (j - 1 >= 0 && board[i][j - 1] != 2) board[i][j - 1] = 1;
				if (j + 1 < w && board[i][j + 1] != 2) board[i][j + 1] = 1;
			}
			else if (c == 'S') start_point = {i, j};
			else if (c == 'E') end_point = {i, j};
		}
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			dis[i][j] = -1;

	dis[start_point.X][start_point.Y] = 0;
	check_que.push(start_point);

	ground_move_bfs(start_point);
	
	return 0;
}
// 인접한 벽인지 체크
// 인접한 벽이면 그대로 두고 queue에 push
// 그리고 sort
// 정렬말고 queue를 두개만들어서 인접한땅에서 주변 인접한 땅이 잇으면 다른 queue에 push
// 두번째 queue가빌때까지 그 안에서 또 반복문을 돌림