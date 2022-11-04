// 백준 1932번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr[502][502];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, nb;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - (n - i); j++)
		{
			cin >> nb;
			arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + nb;
		}
	}

	// for(int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n - (n - i); j++)
	// 		cout << arr[i][j] << ' ';
	// 	cout << '\n';
	// }

	cout << *max_element(arr[n] + 1, arr[n] + n + 1); // 1인덱스로 세기때문에 +1을 해줘야함
}
/*
		7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5

아래 요소를 선택할떄는 왼쪽 대각선과 오른쪽 대각선만 가능
왼쪽 아래는 인덱스를 그대로 받고 오른쪽은 +1해버리면...?

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

사실상 이런 모습으로
근데 시간 복잡도가 문제가 될것같음

매 요소마다 최소값을 고르는게 아니라 결과적으로 최소값이 되야함
우선 왼쪽아래는 인덱스 - 1 오른쪽아래는 그대로

그냥 1 인덱스로 두면 -1 했을때 0이되는 경우의
예외처리를 안해줘도 됨
어차피 0이랑 더한 값에서 max를 하면 값이 들어갈일이 없기때문

min, max_element <- 주소값을 반환해주니 앞에 *를 붙여야함
*/