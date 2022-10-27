// 백준 5648번 문제

#include <iostream>
#include <vector>

using namespace std;

long long arr[1000000];

int d = 13; // 13자리수
long long p10[13]; // 13자리까지 맨끝자리수 추출용
vector<long long> ls[10]; // 0 ~ 9 까지 리스트

int digitNumber(long long nb, int p)
{
	return (nb / p10[p]) % 10; // nb / p10[p] << 원하는 숫자가 끝의 자리에 오도록 조절
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		long long temp_copy = arr[i], temp_reverse = 0;
		while (temp_copy / 1 != 0)
		{
			temp_reverse *= 10;
			temp_reverse += temp_copy % 10;
			temp_copy /= 10;
		}
		arr[i] = temp_reverse;
	}

	// radix sort 기수정렬

	p10[0] = 1;
	for(int i = 1; i < d; i++) p10[i] = p10[i - 1] * 10;

	for(int i = 0; i < d; i++) // 자릿수별로 반복
	{
		for (int j = 0; j < 10; j++) ls[j].clear();

		for (int j = 0; j < n; j++) // 배열의 모든 요소를 탐색
			ls[digitNumber(arr[j], i)].push_back(arr[j]); // 해당 인덱스에 배열처럼 push함, 이중배열같은 모양이 됨, j를 :가 아니라 직접 인덱스로 쓰는 이유
		
		int arr_index = 0;
		for (int j = 0; j < 10; j++)
			for (long long x : ls[j]) arr[arr_index++] = x; // ls[j]에 있는 배열의 요소들을 순서대로 덮어씌우는 작업
	}

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}
// 진법 변환 활용해서 수 뒤집기 후에 정렬