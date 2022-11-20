// 백준 2847번 문제

#include <iostream>

using namespace std;

int arr[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int result = 0, target = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		while (arr[i] >= target)
		{
			arr[i]--;
			result++;
		}
		target = arr[i];
	}
	cout << result;
}