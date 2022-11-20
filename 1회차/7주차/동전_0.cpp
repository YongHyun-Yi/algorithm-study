// 백준 11047번 문제

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[10], result = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--)
	{
		result += k / arr[i]; // 가격이 아니라 횟수를 구하는것...문제 헛갈리지 말것
		k %= arr[i];
	}

	cout << result;
}
// 배수관계라서 성립가능한 풀이임...!