// 백준 16933번 문제

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
int board[1000][1000];
int dis[1000][1000][10][2]; // 0 밤 1 낮

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	
	dis[0][0][0][0] = 1;
	queue<tuple<int, int, int, int>> check_que;
	check_que.push({0, 0, 0, 0});
	while (check_que.size())
	{
		tuple<int, int, int, int> select = check_que.front();
		check_que.pop();

		int sel_x = get<0>(select);
		int sel_y = get<1>(select);
		int sel_cnt = get<2>(select);
		int sel_isnight = get<3>(select);

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = sel_x + dx[dir];
			int ny = sel_y + dy[dir];

			if (nx == n - 1 && ny == m - 1) // 탈출
			{
				cout << dis[sel_x][sel_y][sel_cnt][sel_isnight] + 1 << '\n';
				return 0;
			}

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 보드를 넘어갔을때

			if (board[nx][ny] == 1) // 벽을 만났을때
			{
				if (sel_cnt >= k || dis[nx][ny][sel_cnt + 1][1] > 0) continue; // 더이상 부술수없거나 방문했으면 continue

				if (sel_isnight)
				{
					dis[sel_x][sel_y][sel_cnt][0] = dis[sel_x][sel_y][sel_cnt][sel_isnight] + 1;
					check_que.push({sel_x, sel_y, sel_cnt, 0});
				}
				else
				{
					dis[nx][ny][sel_cnt + 1][1] = dis[sel_x][sel_y][sel_cnt][sel_isnight] + 1;
					check_que.push({nx, ny, sel_cnt + 1, 1});
				}
				// 처음에는 낮일때 +1 밤일때 +2 해서 다음걸 queue에 넣어줫음
				// 이 꼼수로는 벽이 둘러쳐있어도 벽을 제외하고 가장 가까이에 잇는 dis가 먼저 도착해버림
				// 기다리는게 아니라 +2를 해버린걸 같은 한 타임에 돌아버리기때문
				//
				// 정말 벽에서 dis를 기록하지않고 한번더 돌아야함
				// 낮밤 상관없이 벽으로 이동하고
				// 현재칸이 벽일때 현재가 밤일때 bfs돌리고 낮일때는 현재 dis에 +1?
				//
				// 현재가 밤이라서 벽을 못깨면 같은 sel_x sel_y의 낮 배열에 원래 넘겨줘야햇던 거리 +1 을 대입
				// while문이 한바퀴돌고 다시 낮에 bfs가 돌아서 한번더 +1 을 하니 결과적으로 +2가되고
				// 한번 대기했다가 진행하는거랑 같은 결과가됨
			}
			else // 빈칸일때
			{
				int temp = (sel_isnight != 1);
				if (dis[nx][ny][sel_cnt][temp] > 0) continue;
				
				dis[nx][ny][sel_cnt][temp] = dis[sel_x][sel_y][sel_cnt][sel_isnight] + 1;
				check_que.push({nx, ny, sel_cnt, temp});
			}
		}
	}
	cout << "-1\n";
	return 0;
}