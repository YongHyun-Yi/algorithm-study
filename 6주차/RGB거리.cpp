// 백준 1149번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int R[1001];
int G[1001];
int B[1001];
int arr[1001][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> R[i];
		cin >> G[i];
		cin >> B[i];
	}

	arr[1][0] = R[1];
	arr[1][1] = G[1];
	arr[1][2] = B[1];

	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + R[i]; // 색이 중복되면 안되니 1, 2 를 참조
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + G[i];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + B[i];
	}

	int result;
	result = min(arr[n][0], arr[n][1]);
	result = min(result, arr[n][2]);
	cout << result;
}