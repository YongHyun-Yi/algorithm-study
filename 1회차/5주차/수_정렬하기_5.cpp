// 백준 15688번 문제, counting sort

#include <iostream>

using namespace std;

int arr[2000002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[num + 1000000]++;
	}

	for (int i = 0; i < 2000002; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << i - 1000000 << '\n';
	}
}