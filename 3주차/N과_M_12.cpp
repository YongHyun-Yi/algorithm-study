// 백준 15666번 문제

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

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if ((x > 0 && board[x - 1] > numbers[i]) || temp == numbers[i]) continue;

		board[x] = numbers[i];
		temp = numbers[i];
		rec(x + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	sort(numbers, numbers + n);

	rec(0);
}