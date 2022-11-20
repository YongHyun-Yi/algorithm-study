// 백준 15657번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, numbers[8], board[8];

void rec(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (x > 0 && board[x - 1] > numbers[i]) continue;

		board[x] = numbers[i];
		rec(x + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	sort (numbers, numbers + n);

	rec(0);
}