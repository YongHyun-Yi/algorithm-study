#include <iostream>
#include <algorithm>
using namespace std;

// 백준 10818번 문제

int main()
{
	int n;
	int *arr;
	
	cin.tie(NULL);
	
	cin >> n;
	arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[0] << " " << arr[n - 1];
	return 0;
}