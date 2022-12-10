// 백준 2240번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int input[1001];
int dp[1001][31]; // 현재 몇 초인지, 현재까지 움직인 수

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, w;
	cin >> t >> w;
	
	for (int i = 1; i <= t; i++)
		cin >> input[i];

	for (int i = 1; i <= t; i++)
	{
		dp[i][0] = dp[i - 1][0] + (input[i] == 1);
		for (int j = 1; j <= w; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (input[i] == j % 2 + 1);
	}
		// 위의 반복문에서 움직인 횟수가 0인 경우도 함께 계산하면
		// j - 1 에서 인덱스에 음수값이 들어가 잘 못된 참조가 된다
		// 그러니 0번 움직인 경우를 미리 채우고 나머지는 반복문에서 처리한다

	cout << *max_element(dp[t], dp[t] + w + 1);
}