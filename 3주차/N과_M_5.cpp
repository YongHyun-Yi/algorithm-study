// 백준 15654번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, numbers[8], board[8], is_used[10];

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
		if (is_used[i]) continue;

		is_used[i] = 1;
		board[x] = numbers[i];
		rec(x + 1);
		is_used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	sort(numbers, numbers + n);

	rec(0);
}