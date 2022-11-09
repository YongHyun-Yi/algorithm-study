// 백준 11399번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	int result = 0, current = 0;
	for (int i = 0; i < n; i++)
	{
		current += arr[i];
		result += current;
	}

	cout << result;
}

// 그리디보단 그냥 정렬로 푼거같음;
// 아직도 그리디가 뭔지 모르겠음...
//
// << 인터넷에서 찾아본 풀이 >>
// result += arr[i] * (n-i);
// 예를 들어, sort 후에 {1, 2, 3, 4, 5}일 때
// 1은 5번 더해지고 2는 4번, 3은 3번, 4는 2번, 5는 1번 더해진다.
// 그걸 이용해서 line[i] * (n-i) 값을 모두 더해준다. 