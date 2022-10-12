// 백준 15650번 문제

#include <iostream>

using namespace std;

int n, m, board[8], is_used[9];

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
		if (!is_used[i])
		{
			if (x > 0 && board[x - 1] >= i) continue;

			is_used[i] = 1;
			board[x] = i;
			rec(x + 1);
			is_used[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rec(0);
}