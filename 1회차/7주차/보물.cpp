// 백준 1026번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr_a[50];
int arr_b[50];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr_a[i];
	for (int i = 0; i < n; i++) cin >> arr_b[i];

	sort(arr_a, arr_a + n);
	sort(arr_b, arr_b + n);

	int result = 0;
	for (int i = 0; i < n; i++)
		result += arr_a[i] * arr_b[n - i - 1];
	
	cout << result;
}