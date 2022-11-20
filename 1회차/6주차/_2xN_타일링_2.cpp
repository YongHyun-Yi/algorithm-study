// 백준 11727번 문제

#include <iostream>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	arr[1] = 1;
	arr[2] = 3;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) arr[i] = (arr[i - 1] + (arr[i - 2] * 2)) % 10007;

	cout << arr[n];
}
// 1x2랑 2x2랑 같은 패턴으로 들어감
// 이 부분만 따로 뺴서 *2를 할수있으면 좋을거같은데...