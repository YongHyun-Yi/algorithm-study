// 백준 2630번 문제

#include <iostream>

using namespace std;

int board[128][128];
int cnt[2]; // 0, 1

bool serch(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != board[x][y])
				return false;
	return true;
}

void rec(int n, int x, int y)
{
	if (serch(n, x, y))
	{
		cnt[board[x][y]]++;
		return ;
	}

	n /= 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			rec(n, x + i * n, y + j * n);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	rec(n, 0, 0);

	for (int i : cnt)
		cout << i << '\n';
}