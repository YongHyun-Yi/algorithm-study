// 백준 15664번 문제

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

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if ((x > 0 && board[x - 1] > numbers[i]) || temp == numbers[i] || is_used[i]) continue; // 이전수보다 작거나 중복되면 패스, 후에 중복되는 수가 나오는건 앞의 조건문에 넣으면 짤리니 is_used를 쓸 수 밖에...

		is_used[i] = 1;
		board[x] = numbers[i]; // x를 i로 잘못써버리는 실수...조심할것!
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