// 백준 1912번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001]; // 누적합 or 갱신값을 담는 배열

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, current;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> current;
		if (arr[i - 1] + current >= current) arr[i] = arr[i - 1] + current;
		else arr[i] = current;
			// 이전까지의 누적합 + 현재값 >= 현재값 이라면 배열에 누적합을 대입
			// 그렇지 않으면 현재값만 대입
	}

	cout << *max_element(arr + 1, arr + 1 + n);
		// 모든 연산이 끝난후 최대값을 가진 요소만 뽑아냄
}
// 연속해서 더한값 vs 바로 직전거랑 더한값
// 전자가 이기면 계속해서 더해나감
// 후자나 이기면 갱신
//
// 변수 하나만 쓸려고햇는데 안됨...
// 우선 배열에다가 연속한값 혹은 갱신한값을 대입
// 그 후에 최대값을 가진 요소 하나를 골라냄