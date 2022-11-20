#include <iostream>

using namespace std;

int arr[1000]; // ex n이 1~1000 일경우

int main()
{
	int n, nb;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nb;
		arr[nb - 1]++; // 입력값을 인덱스로 사용, 입력시마다 값을 증가
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i]; j++)
			cout << i + 1 << ' '; // 작은 인덱스부터 값이 1이상이면 출력
}