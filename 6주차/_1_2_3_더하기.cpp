// 백준 9095번 문제

#include <iostream>

using namespace std;

int arr[12];

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for (int i = 4; i <=n; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		
		cout << arr[n] << '\n';
	}
}
// 1, 2, 3을 이용해서 이들의 합으로 나타내는 경우의 수
//
// 개선할 사항 - n의 범위가 적으니
// 미리 배열을 다 구해놓고 입력을 받으면
// 바로 arr[n]을 출력하도록 하는게 효율적