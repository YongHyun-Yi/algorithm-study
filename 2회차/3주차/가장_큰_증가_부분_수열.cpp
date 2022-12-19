// 백준 11055번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = a[i];
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + a[i]);

	cout << *max_element(dp + 1, dp + n + 1);
}