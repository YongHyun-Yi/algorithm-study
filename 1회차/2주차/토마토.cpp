// 백준 7576번 문제

#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int dis[1000][1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <m; j++)
			cin >> board[i][j];

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	queue<pair<int, int>> check_que;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] > 0) check_que.push({i, j});
			else if (board[i][j] == 0) dis[i][j] = -1;
				// << 영상 해설보고 배운것 >>
				// 익지 않은 애들만 따로 구분해줘야
				// 맨 마지막 결과에서 전혀 익지않은
				// 반복문의 영향을 받지않은 토마토를 찾을수있음
		}
	}

	int answer = 0;
	while (!check_que.empty())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.first + dx[dir];
			int ny = select.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1 || dis[nx][ny] >= 0) continue;
			dis[nx][ny] = dis[select.first][select.second] + 1;
			check_que.push({nx, ny});
			// if (dis[nx][ny] > answer) answer = dis[nx][ny];
			// << 영상 해설보고 배운것 >>
			// answer에 값을 비교해서 넣는것은 마지막에
			// 오류도 찾아낼겸 한번에 2중반복문 돌리면서
			// 최대한 여러가지 일을 한 번에 할수있도록 설계
		}
	}
	// cout << "-----------------------------------------\n";
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <m; j++)
		{
			if (dis[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			answer = max(answer, dis[i][j]);
		}
	}
	cout << answer;	
}

// 반복문으로 queue에 들어갈 시작점을 모두 찾아서 push하기
// queue가 빌때까지 반복