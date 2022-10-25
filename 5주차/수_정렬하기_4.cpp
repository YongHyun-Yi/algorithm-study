// 백준 11931번 문제

#include <iostream>

using namespace std;

int arr[2000002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		int nb;
		cin >> nb;
		arr[nb + 1000000]++;
	}

	for (int i = 2000001; i >= 0; i--)
		for (int j = 0; j < arr[i]; j++)
			cout << i - 1000000 << '\n';
}