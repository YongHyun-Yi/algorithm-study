// 백준 16236번 문제

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, cnt = 0, shark_size = 2, time = 0;
int board[20][20];
int dis[20][20];
pair<int, int> shark_pos;
vector<tuple<int, int, int>> eatable; // 거리, x, y

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs()
{
	bool flag = true;
	while (flag)
	{
		flag = false;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = -1;
		eatable.clear();
		
		queue<pair<int, int>> check_que;
		dis[shark_pos.X][shark_pos.Y] = 0;
		check_que.push(shark_pos);

		while (check_que.size())
		{
			pair<int, int> select = check_que.front();
			check_que.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = select.X + dx[dir];
				int ny = select.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] > shark_size || dis[nx][ny] > -1) continue;

				dis[nx][ny] = dis[select.X][select.Y] + 1;
				check_que.push({nx, ny});

				if (board[nx][ny] < shark_size && board[nx][ny] > 0)
					eatable.push_back({dis[nx][ny], nx, ny});
						// 먹을수 있는 물고기는 우선 벡터에넣고 정렬
			}
			if (flag) break ;
		}

		if (eatable.size() > 0)
		{
			flag = true;
				// 하나이상의 먹을수있는 물고기가 있으면 bfs를 반복한다

			sort(eatable.begin(), eatable.end());
				// 정렬하면 가장 가까운 거리의 물고기
				// 가장 가까운 물고기가 여럿이면 좌표가 작은 순서
				// 즉 좌상단에 가장 가까운 물고기부터 먹음

			tuple<int, int, int> temp = eatable[0];
			int temp_dis = get<0>(temp);
			int temp_x = get<1>(temp);
			int temp_y = get<2>(temp);

			board[shark_pos.X][shark_pos.Y] = 0; // 보드에서 상어 제거
			shark_pos = {temp_x, temp_y}; // 먹을 물고기가 있는곳에 상어 놓기
			board[shark_pos.X][shark_pos.Y] = 9;
			time += temp_dis; // 거리만큼 시간 추가
			cnt++; // 먹은수 추가
			
			if (cnt == shark_size)
			{
				shark_size++;
				cnt = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
				shark_pos = {i, j};
		}
	}
	
	bfs();

	cout << time;
}