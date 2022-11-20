// 백준 1926번 문제

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	int board[500][500];
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			cin >> board[i][j];
	// 입력값에 따라 보드 초기화

	queue<pair<int, int>> check_que;
	bool visited[501][501];

	int biggest_size = 0;
	int picture_count = 0;

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (!board [i][j] || visited[i][j]) continue;

			check_que.push({i, j});
			visited[i][j] = 1;
			picture_count++; // 유효한 그림의 시작점 수

			int picture_size = 0;
			while (!check_que.empty())
			{
				pair<int, int> select = check_que.front();
				check_que.pop();
				picture_size++; // 해당 그림에 들어있는 1의 수

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = select.first + dx[dir];
					int ny = select.second + dy[dir];
						// 선택한 좌표 + 체크할 좌표
					
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (!board [nx][ny] || visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					check_que.push({nx, ny});
				}
			}
			biggest_size = max(picture_size, biggest_size);
		}
	}
	cout << picture_count << '\n' << biggest_size;
}