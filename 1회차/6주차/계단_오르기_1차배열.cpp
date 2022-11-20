// 백준 2579번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int stair[301];
int arr[301];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
		result += stair[i]; // for 문을 하나 더 줄이기위해서 미리 계산
	}

	if (n <= 2)
	{
		cout << result;
		return 0;
			// 예외처리, 맨 밑 출력에서 n - 2까지 쓰니 2까지 예외처리한듯
	}

	arr[1] = stair[1];
	arr[2] = stair[2];
	arr[3] = stair[3]; // 어째서...?

	for (int i = 4; i <= n; i++)
		arr[i] = min(arr[i - 2], arr[i - 3]) + stair[i];
	
	cout << result - min(arr[n - 1], arr[n - 2]);
}

// 설명이 굉장히 헛갈림...
// 대충 갈피만 잡은정도