// 백준 12852번 문제

#include <iostream>

using namespace std;

int arr[1000001];
int pre_arr[1000001]; // 이전의 인덱스만 담을 배열

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	arr[1] = 0;

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		pre_arr[i] = i - 1;

		if (i % 3 == 0 && arr[i] > arr[i / 3] + 1)
		{
			arr[i] = arr[i / 3] + 1;
			pre_arr[i] = i / 3;
		}

		if (i % 2 == 0 && arr[i] > arr[i / 2] + 1)
		{
			arr[i] = arr[i / 2] + 1;
			pre_arr[i] = i / 2;
		}
	}
		// pre_arr에 유효한 인덱스를 덮어쓴다
		// min으로 쓴 부분을 풀어써준다
		// min으로 처리하면 어떤 인덱스가 덮어씌워지는지 알 수 없기때문

	cout << arr[n] << '\n';

	int current = n;
	while(1)
	{
		cout << current << ' ';

		if (current == 1) break;

		current = pre_arr[current];
	}
		// 야매 연결리스트랑 비슷하게 구현이라는데
		// 천천히 살펴봐야할듯...
		// 우선 현재값을 출력하고나서 진행한다는점에 유의
}