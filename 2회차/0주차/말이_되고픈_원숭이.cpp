// 백준 1600번 문제

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int k, w, h;
int board[200][200];
int dis[200][200][30];
queue<tuple<int, int, int>> check_que;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int h_dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int h_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];
	
	check_que.push({0, 0, 0});
	while (!check_que.empty())
	{
		tuple<int, int, int> select = check_que.front();
		int select_x = get<0>(select);
		int select_y = get<1>(select);
		int select_cnt = get<2>(select);
		check_que.pop();

		if (select_x == h - 1 && select_y == w - 1) // 도착지점에 도달하면 출력, 따로 명시해준 이유는 몇번째 k이동후에 도착하는지 확실하지 않아서
		{
			cout << dis[select_x][select_y][select_cnt];
			return 0;
		}

		if (select_cnt < k) // 말 이동, 여기서 continue를 해버리면 뒤의 원숭이 이동이 씹힌다, 순서를 바꾸면 괜찮을지도...?, 일단 말 이동을 우선으로 하고싶었음
		{
			for (int dir = 0; dir < 8; dir++)		
			{
				int nx = select_x + h_dx[dir];
				int ny = select_y + h_dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == 1 || dis[nx][ny][select_cnt + 1] > 0) continue;
				dis[nx][ny][select_cnt + 1] = dis[select_x][select_y][select_cnt] + 1;
				check_que.push({nx, ny, select_cnt + 1});
			}
		}

		for (int dir = 0; dir < 4; dir++) // 원숭이 이동
		{
			int nx = select_x + dx[dir];
			int ny = select_y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == 1 || dis[nx][ny][select_cnt] > 0) continue;
			dis[nx][ny][select_cnt] = dis[select_x][select_y][select_cnt] + 1;
			check_que.push({nx, ny, select_cnt});
		}
	}
	cout << "-1";
}