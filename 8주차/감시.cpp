// 백준 15683번 문제

#include <iostream>

using namespace std;

int board[8][8];
pair<int, int> dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	cout << "----------------------\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	for (int dir = 0; dir < n; dir++)
	{
		int nx = 2, ny = 3;
		cout << board[nx + dxy[dir].first][ny + dxy[dir].second] << ' ';
	}
	// 입력 테스트
}