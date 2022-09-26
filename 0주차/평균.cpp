#include <iostream>
#include <algorithm>
using namespace std;

// 백준 1546번 문제

int main()
{
	int n;
	cin >> n;
	double arr[1000], result = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		result += (arr[i] / arr[n - 1]) * 100;
	result /= n;
	cout << result;
	return 0;
}