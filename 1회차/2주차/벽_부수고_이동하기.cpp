// 백준 2206번 문제

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define X first
#define Y second

using namespace std;

char board[1000][1000];
int dis[1000][1000][2];
	// << 해설 보고 배운것 >>
	// 먼저 부수는게 최적일지 몰라도 후에 벽을 부숴야만 통과 할 수 있는경우를 생각해보면 3차원인 이유를 알 수 있음
	// 0 안 부순 경우의 수, 그냥 bfs
	// 1 부순 경우의 수, 위의 0번쨰 배열들이 모두 시작점이 될수있다
	// 불! 문제와는 살짝 다른 개념으로 dis 배열을 더 사용하는 셈
queue<tuple<int, int, int>> check_que;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	dis[0][0][0] = dis[0][0][1] = 1;
	check_que.push({0, 0, 0}); // 좌표, 벽 부쉈는지 여부

	while (!check_que.empty())
	{
		tuple<int, int, int> select = check_que.front();
		check_que.pop();

		if (get<0>(select) == n - 1 && get<1>(select) == m - 1) // 탈출조건
			{
				cout << dis[get<0>(select)][get<1>(select)][get<2>(select)];
				// cout << "------------------------------\n";
				// for (int i = 0; i < n; i++)
				// {
				// 	for (int j = 0; j < m; j++)
				// 	{
				// 		cout << dis[i][j] << " ";
				// 	}
				// 	cout << "\n";
				// }
				return 0;
			}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<0>(select) + dx[dir];
			int ny = get<1>(select) + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dis[nx][ny][get<2>(select)] > 0) continue;
			if (board[nx][ny] == '1') // 벽을 만났을 때
			{
				if (get<2>(select)) continue; // 이미 부쉈으면 continue;
				else // 아니면 dis에 +1하고 queue에 벽 부쉈음을 1로 변경해서 push
				{
					dis[nx][ny][1] = dis[get<0>(select)][get<1>(select)][get<2>(select)] + 1;
					check_que.push({nx, ny, 1});
					continue;
				}
			}

			dis[nx][ny][get<2>(select)] = dis[get<0>(select)][get<1>(select)][get<2>(select)] + 1;
			check_que.push({nx, ny, get<2>(select)}); // 벽 부쉈는지 여부는 계속 보존해서 넘겨줌
		}
	}
	cout << -1;

	return 0;
}

// ---------------------------------------------------
// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			cin >> board[i][j];
	
// 	for (int i = 0; i < n; i++)
// 		fill(dis[i], dis[i] + m, -1);
	
// 	dis[0][0] = 0;
// 	check_que.push({0, 0});

// 	while (!check_que.empty())
// 	{
// 		pair<int, int> select = check_que.front();
// 		check_que.pop();

// 		for (int dir = 0; dir < 4; dir++)
// 		{
// 			int nx = select.X + dx[dir];
// 			int ny = select.Y + dy[dir];

// 			if (nx >= n - 1 && ny >= m - 1) // 탈줄조건
// 			{
// 				cout << dis[select.X][select.Y] + 1;
// 				return 0;
// 			}

// 			if (nx < 0 || ny < 0 || dis[nx][ny] >= 0) continue;
// 			if (board[select.X][select.Y] =='1' && board[nx][ny] == '1') continue;

// 			dis[nx][ny] = dis[select.X][select.Y] + 1;
// 			check_que.push({nx, ny});

// 			if (board[nx][ny] =='1') dis[nx][ny] += 1;
// 		}
// 	}
// 	cout << -1;
// }

// bool 변수 하나를 두고 벽을 한번 만나면 4방향을 모두 체크하고
// 벽만 dis에 +2한채 추가하는걸 생각했으나 벽이 여러개 있는 구간과
// 벽이 하나만 있는 구간이 있는 지도의 경우
// 앞에서 벽이 두개짜리인 곳에서 bool변수를 써버리면
// 뒤의 벽이 하나만 있는 구간에서 쓸수가 없음
// 통과할수 있는 지도임에도 불구하고 에러가 출력되버림
// 벽을 부숴보고 탐색하는길을 여러개 돌려봐야함
// 부숴본 벽인지 아닌지를 남길 필요가있음
// 현재 벽이 부순벽인데 벽을 또 만난다? -> 바로 continue;
// 벽을 만났을때 board[select.x][select.y]를 비교?
// 땅일때 벽을 넣어볼수있지만 벽일때는 벽을 넣을수 없음

// 벽을 부수고 또 부술수있음
// 벽을 부쉈는지를 보존한채로 queue에 넣어질 필요가 있음