// 백준 2193번 문제

#include <iostream>

using namespace std;

long long arr[91][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	arr[1][0] = 0;
	arr[1][1] = 1;

	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0) arr[i][j] = arr[i - 1][0] + arr[i - 1][1];
			else  arr[i][j] = arr[i - 1][0];
		}
	}

	cout << arr[n][0] + arr[n][1];
}

/*
	d[n] n번째 자리까지의 이친수의 갯수...?
	앞자리가 0이면 뒤에는 0과 1이 올수있다
	앞자리가 1잉면 뒤에는 0밖에 올수없다
	0으로 끝나면 [0]에 1로 끝나면[1]에 저장하기?

	1 = 1 / 0 1
	2 = 2 / 1 0
	3 = 4 / 1 1
	4 = 7 / 2 1
	5 = 12 / 3 2
	6 = 20 / 5 3
	양쪽껄 합쳐서 왼쪽으로, 오른쪽은 그냥 그대로 +1...?
	n = (n - 1) + (n - 2) + 1 이렇게 하면 대충 작은수는 들어맞는데 큰수에서 틀리는지...?

	그냥 2차배열이 맞는것같음...
	0으로 끝나면 0과 1모두 올수잇고 [i][0] = [i - 1][0] + [i - 1][1]
	1로 끝나면 0밖에 올수없음 [i][1] = [i - 1][0]

	↑ 그냥 위의 계산표가 틀렸음 ㅋㅋㅋㅋㅋㅋ
	n의 자리까지 나올수있는 모든 경우의 수를 세는게 아니라
	그냥 n의 자리에서 나올수있는 경우의 수였음...
	여태 게속 누적합만 하다보니 문제를 잘못이해함 ㅋㅋㅋ
*/