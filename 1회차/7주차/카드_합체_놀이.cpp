// 백준 15903번 문제

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	long long temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	while (m--)
	{
		sort(arr, arr + n);
		temp = arr[0] + arr[1];
		arr[0] = temp,arr[1] = temp;
	}

	long long result = 0;
	for (int i = 0; i < n; i++) result += arr[i];
	cout << result;
}