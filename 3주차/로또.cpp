// 백준 6603번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n = -1, numbers[49], board[6];

void rec(int x)
{
	if (x == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (x > 0 && board[x - 1] >= numbers[i]) continue;

		board[x] = numbers[i];
		rec(x + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (n != 0)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		
		rec(0);
		cout << '\n';
	}
	return 0;
}