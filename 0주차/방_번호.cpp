#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 1475번 문제

int main()
{
	vector<int> arr(10);
	int nb;
	cin >> nb;
	while (nb)
	{
		arr[nb % 10]++;
		nb /= 10;
	}
	arr[6] = ((arr[6] + arr[9]) / 2) + ((arr[6] + arr[9]) % 2);
	arr[9] = arr[6];
	sort(arr.begin(), arr.end());
	cout << arr[9];
	return 0;
}