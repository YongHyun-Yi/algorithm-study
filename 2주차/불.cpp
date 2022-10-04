// 백준 4179번 문제

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define X first
#define Y second

string board[1000];
int j_dis[1000][1000];
int f_dis[1000][1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int R,C;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	queue<pair<int, int>> check_que;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (board[i][j] == 'F') check_que.push({i, j});
			else f_dis[i][j] = -1;
	
	pair<int, int> select;
	while (!check_que.empty())
	{
		select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#' || f_dis[nx][ny] >= 0) continue;
			f_dis[nx][ny] = f_dis[select.X][select.Y] + 1;
			check_que.push({nx, ny});
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'J') check_que.push({i, j});
			else j_dis[i][j] = -1;
		}
	}

	while (!check_que.empty())
	{
		select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << j_dis[select.X][select.Y] + 1;
				return 0;
			}
				// << 영상 해설보고 배운것 >>
				// 이전의 문제들이였다면 탐색범위 밖이니까
				// 런타임 에러를 피하기 위해서 continue를 했지만
				// 이 문제에서는 지훈의 탈출조건이 됨
				// 즉 종료조건
			if (board[nx][ny] == '#' || j_dis[nx][ny] >= 0) continue;
			if (f_dis[nx][ny] != -1 && f_dis[nx][ny] <= j_dis[select.X][select.Y] + 1) continue;
				// f_dis가 -1가 나오려면 벽일수밖에 없는데
				// 이미 위의 조건문에서 벽이면 continue를 해줬는데
				// 왜 이 조건때문에 답이 갈리는지 모르겠음....
				// << 댓글 설명보고 알게된것 >>
				// 3 4
				// # # # F
				// . J # .
				// # # # .
				// 불이 벽을 제외한 모든 칸을 지나갈거라 생각했지만
				// 위 처럼 불이 갇혀있는 상태 혹은 불과 지훈이
				// 벽으로 분리되어있는 상태에서는 지훈이가 갈 수
				// 있는곳을 불은 갈수없기때문에 -1 초기값으로
				// 남아있게됨 이러한 경우를 위해서 조건을 추가한것
			j_dis[nx][ny] = j_dis[select.X][select.Y] + 1;
			check_que.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";

	// cout << "------------fire-----------\n";
	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 		cout << f_dis[i][j] << " ";
	// 	cout << "\n";
	// }
	// cout << "------------jihun-----------\n";
	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 		cout << j_dis[i][j] << " ";
	// 	cout << "\n";
	// }
	// cout << "----------------------------\n";
	
	// int answer = 1000;
	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 	{
	// 		if ((i == 0 || i == R - 1) || (j == 0 || j == C - 1))
	// 		{
	// 			if (j_dis[i][j] > 0)
	// 			{
	// 				answer = min(answer, j_dis[i][j]);
	// 			}
	// 		}
	// 	}
	// }
	// if (answer != 1000) cout << answer + 1;
	// else cout << "IMPOSSIBLE";
		// << 영상 해설보고 배운것 >>
		// 토마토 문제에서는 마지막에 2중반복문을 돌려서
		// 에러를 찾아내고 그렇지 않으면 최대값을 찾아냈는데
		// 이 문제에서는 이미 위의 탈출조건에 닿지 못했으니
		// 실패한 상황이 됨
}