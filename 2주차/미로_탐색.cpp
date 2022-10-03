// 백준 2178번 문제

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string board[100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	
	int dis[100][100];
	for (int i = 0; i < n; i++)
		fill(dis[i], dis[i] + m, -1);
	
	int dx[4] = {1, 0, -1 ,0};
	int dy[4] = {0, 1, 0 ,-1};

	queue<pair<int, int>> check_que;
	check_que.push({0, 0});
	dis[0][0] = 1;

	while(!check_que.empty())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.first + dx[dir];
			int ny = select.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != '1' || dis[nx][ny] > 0) continue;
			dis[nx][ny] = dis[select.first][select.second] + 1;
			check_que.push({nx, ny});
		}
	}
	cout << dis[n - 1][m - 1];
}
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
	
// 	int n, m;
// 	cin >> n >> m;

// 	int board[100][100];
// 	for (int i = 0; i < n; i++)
// 	{
// 		string str;
// 		cin >> str;
// 		for (int j = 0; j < m; j++)
// 		{
// 			board[i][j] = str[j] - '0';
// 		}
// 	}
	
// 	int dis[100][100];
// 	fill(dis[0], dis[100], -1);
// 	int dx[4] = {1, 0, -1, 0};
// 	int dy[4] = {0, 1, 0, -1};

// 	queue<vector<int>> check_que; // distance도 보존해서 넘겨주기, 본인이 계승받은 값에만 더해줌
// 	check_que.push({0, 0, 1}); // x, y, distance
	
// 	while (!check_que.empty())
// 	{
// 		vector<int> select = check_que.front();
// 		check_que.pop();
// 		dis[select[0]][select[1]] = select[2];

// 		for (int dir = 0; dir < 4; dir++)
// 		{
// 			int nx = select[0] + dx[dir];
// 			int ny = select[1] + dy[dir];
// 			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
// 			if (!board[nx][ny] || dis[nx][ny] > 0) continue;
// 			check_que.push({nx, ny, select[2] + 1});
// 		}
// 	}
// 	cout << dis[n-1][m-1];
// }

// 메모리초과 발생