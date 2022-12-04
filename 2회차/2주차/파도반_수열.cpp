// 백준 9461번 문제

#include <iostream>

using namespace std;
long long board[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		board[0] = 1;
		board[1] = 1;
		board[2] = 1;

		for (int i = 3; i < n; i++)
			board[i] = board[i - 3] + board[i - 2];
		cout << board[n - 1] << '\n';
	}
}