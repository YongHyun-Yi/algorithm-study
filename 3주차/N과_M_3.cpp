// 백준 15651번 문제

#include <iostream>

using namespace std;

int n, m, board[7];

void rec(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		board[x] = i;
		rec(x + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rec(0);
}