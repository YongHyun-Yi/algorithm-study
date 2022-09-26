#include <iostream>
using namespace std;

// 백준 2562번 문제

int main()
{
	int arr[9];
	int mx = -1;
	int index;
	
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
			index = i + 1;
		}
	}
	cout << mx << "\n" << index;
}