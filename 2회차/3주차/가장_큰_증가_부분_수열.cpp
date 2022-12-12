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
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= a[i - 1])
			dp[i] = dp[i - 1] + a[i]; // 다음 수가 이전 수 보다 크면 == 오름차순이면 더함
		else
			dp[i] = dp[i - 1] - a[i - 1] + a[i]; // 그렇지 않으면 이전 수를 뺌
			// 빼지않고 그냥 다음으로 넘어가는게 더 큰 경우도 있을수있음...어떤식으로 계산?
			// 한번 뺀 후에 더하려는 수도 지금 들어가있는 수보다 작을수있음
			// 현재 가장 위에있는 인덱스를 놔둬야하나?, vector로 넣어놔야하나?
	}

	// cout << *max_element(dp + 1, dp + n + 1);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << ' ';
}