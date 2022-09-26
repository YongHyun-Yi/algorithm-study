#include <iostream>
using namespace std;

// 백준 3052번 문제

int main()
{
	int arr[42] = {};
	int a, count = 0;
	
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		arr[a % 42]++;
	}
	for (int i : arr)
	{
		if (i > 0)
			count++;
	}
	cout << count;
	return 0;
}