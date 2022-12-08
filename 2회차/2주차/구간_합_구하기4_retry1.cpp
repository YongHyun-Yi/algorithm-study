// 백준 11659번 문제

#include <iostream>

using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, nb;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> nb;
		dp[i] = dp[i - 1] + nb;
	}
	
	while(m--)
	{
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}