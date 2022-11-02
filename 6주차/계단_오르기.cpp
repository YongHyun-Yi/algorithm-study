// 백준 2579번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int stair[301];
int arr[301][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> stair[i];

	if (n == 1)
	{
		cout << stair[1];
		return 0;
	}
		// n이 1일경우 아래의 초기값 설정에서 오류가 발생 할 수 있으니 예외처리

	arr[1][1] = stair[1];
	arr[1][2] = 0;
	arr[2][1] = stair[2];
	arr[2][2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++)
	{
		arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + stair[i]; // 연속해서 밟은 인접한 계단이 1개밖에 없음 -> 두계단을 올랐다는 소리, 즉 i - 2를 참조해야함
		arr[i][2] = arr[i - 1][1] + stair[i]; // 연속해서 밟은 인접한 계단이 2개 -> 바로 직전계단 and 1개만 밟은 배열을 참조
	}

	cout << max(arr[n][1], arr[n][2]);
}

// n번째 계단까지 올라갔을때 얻을수있는 최댓값
// 이전문제처럼 1계단만 올라간경우 +1 2계단 올라간경우 +2... 이런식으로?
// 우선계단을 모두 입력받고 한꺼번에 계산?
// 연속한 3개의 계단을 밟으면 안된다는 조건은 어떤식으로 처리해야하는지...
//
// d[i][j] - i : 몇번째 계단인지, j : 얼만큼 연속해서 밟았는지
// j개의 계단을 연속해서 밟고 i번째 계단까지 올라갔을때 -> 밟은 계단의 수가 아니라 연속해서 붙어있는 계단의 수임
// 점수합의 최댓값, i번째 계단은 반드시 밟아야함
// 이와같이 이차원배열을 사용해야한다고함...
//
// 