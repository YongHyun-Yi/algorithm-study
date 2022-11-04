// 백준 11659번 문제

#include <iostream>

using namespace std;

long long arr[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int nb;
		cin >> nb;
		arr[i] = arr[i - 1] + nb;
	}
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << arr[end] - arr[start - 1] << '\n';
	}
}
// prefix sum 기억해두기