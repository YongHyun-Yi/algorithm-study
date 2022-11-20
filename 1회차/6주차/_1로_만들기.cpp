// 백준 1463번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001]; // 10^6

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	arr[1] = 0; // 초기값, 1이 1이 될때까지 연산해야하는 수

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
	}
		// 배열 채워놓는 선작업
		//
		// 채워놓은 배열에서 마지막에 활용하는게 아니라
		// 목표까지도 for문을 돌려서 작업

	cout << arr[n];
}
// 초기값만 세팅
// 경우의 수를 배열에 저장
// 다른 경우의 수에서 중복되는 부분을
// 이미 저장된 배열을 참조함으로써 재활용
// min 함수는 인자를 3개이상 받을수없다
// 그러면 어떻게 3가지 연산에 대해서 min을 뽑아낼수있는지?
//
// 모든 연산을 하나씩 노가다
// 맨 처음 i - 1은 그냥 대입
// 이후로는 이미 대입되어있는 값과 min값으로 비교해서 대입