// 백준 15665번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, numbers[7], board[7];

void rec(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp == numbers[i]) continue;

		board[x] = numbers[i];
		temp = numbers[i];
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
	
	sort(numbers, numbers + n);

	rec(0);
}