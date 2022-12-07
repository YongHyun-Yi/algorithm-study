// 백준 2579번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int step[301];
int dp[301][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> step[i];
	
	dp[1][1] = step[1];
	dp[1][2] = 0;
	dp[2][1] = step[2];
	dp[2][2] = step[1] + step[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + step[i];
		dp[i][2] = dp[i - 1][1] + step[i];
	}

	cout << max(dp[n][1], dp[n][2]);
}