// 백준 11501번 문제

#include <iostream>

using namespace std;

int arr[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		long long n, result = 0;

		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];

		int mx = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (arr[i] <= mx) result += mx - arr[i];
			else mx = arr[i];
		}
		cout << result << '\n';
	}
}

// 수를 입력받음
// 직전에 입력받은 수보다 크면 계속 더함
// 그렇지 않으면 (방금 입력받은수 * 여태 더한 갯수) - 여태 더한 수를 result에 더함
// 배열같이 참조하면 편할거같은데 일단은 단일변수들 써보기...
//
// 정답보고 배운거
// 가장 마지막 가격을 기준으로 최댓값을 지정
// 그 이전 가격들을 보면서 작으면 더하고 크면 최댓값을 갱신
// 그러면 정방향으로 봤을때는 당시에 최대로 이득볼수있는 타이밍이 맞음