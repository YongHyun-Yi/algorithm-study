// 백준 14502번 문제

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[8][8];
int temp_board[8][8];
int n, m, mx;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int,int>> check_que;

void bfs()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp_board[i][j] = board[i][j]; // 대입연산자 대신 == 넣어놓고 한참 찾아보고있었음 ㅎㅎ;
			if (temp_board[i][j] == 2) check_que.push({i, j});
		}
	}
	
	while(check_que.size())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || temp_board[nx][ny]) continue;

			temp_board[nx][ny] = 2;
			check_que.push({nx, ny});
		}
	}

	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp += (temp_board[i][j] == 0);
	
	mx = max(mx, temp);
}

void rec(int k)
{
	if (k == 3)
	{
		bfs();
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j]) continue;

			board[i][j] = 1;
			rec(k + 1);
			board[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; // cin >> n, m 이렇게 해놓고 왜 바로 입력 끝나는지 몰랏음 ㅎㅎ;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	rec(0);

	cout << mx;
}
