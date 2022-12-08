// 백준 12852번 문제

#include <iostream>

using namespace std;

int dp[1000001];
int dp_log[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 0;
	dp_log[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		dp_log[i] = i - 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = dp[i / 3] + 1;
			dp_log[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			dp_log[i] = i / 2;
		}
	}
	dp_log[n + 1] = n;
	cout << dp[n] << '\n';
	int idx = n + 1;
	do
	{
		cout << dp_log[idx] << ' ';
		idx = dp_log[idx];
	} while (idx > 1);
}