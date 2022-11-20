// 백준 10989번 문제

#include <iostream>

using namespace std;

int n;
int arr[10000];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int nb;
		cin >> nb;
		arr[nb - 1]++;
	}

	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < arr[i]; j++)
			cout << i + 1 << '\n';
}

// 메모리 제한때문에 변수에 담지않는 방법을 써야함 -> counting sort