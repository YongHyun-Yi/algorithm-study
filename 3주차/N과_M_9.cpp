// 백준 15663번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, numbers[8], board[8], is_used[8];

void rec(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
			cout << board[i] << ' ';
		cout << '\n';
		return ;
	}

	int temp = 0; // 이전값과 중복체크용, 무조건 1이상의 수만 들어오니 초기값은 0으로 하면 첫번째도 비교가능
	for (int i = 0; i < n; i++)
	{
		if (is_used[i] || temp == numbers[i]) continue;

		is_used[i] = 1;
		board[x] = numbers[i];
		temp = numbers[i];

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