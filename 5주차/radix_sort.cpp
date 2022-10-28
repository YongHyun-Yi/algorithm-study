#include <iostream>
#include <vector>

using namespace std;

int arr[10] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545}; // 012 처럼 앞에 0이 붙으면 8진법으로 계산되니 주의
int n = 10; // 원소의 개수
int d = 3; // 3자리수
int p10[3]; // 10진수 10의 0, 1, 2승까지 표현
vector<int> ls[10]; // 0 ~ 9 까지 정렬할 리스트

int digitNumber(int nb, int p)
{
	return (nb / p10[p]) % 10; // % 10 << 끝의 자리만 추출, nb / p10[p] 끝의자리 위치를 조절함
}

int main()
{
	p10[0] = 1;
	for (int i = 1; i < d; i++) p10[i] = p10[i - 1] * 10;

	for (int i = 0; i < d; i++) // 각 자릿수별로 정렬을 반복 후 arr에 덮어쓰기
	{
		for (int j = 0; j < 10; j++) ls[j].clear();

		for (int j = 0; j < n; j++) // j < n 인 이유, 여기서 j는 arr의 인덱스로 쓰이기 때문
			ls[digitNumber(arr[j], i)].push_back(arr[j]); // 추출한 값에 해당하는 리스트에 해당 요소를 추가
		
		int arr_index = 0;
		for (int j = 0; j < 10; j++) // 각 자릿수별 0 ~ 9 까지의 리스트
			for (int x : ls[j]) // 해당 리스트에 있는 값을 모두 넣어야 하니 x : 를 사용하여 사이즈에 상관없이 모든 인자를 받아오도록
				arr[arr_index++] = x; // 덮어쓰면서 인덱스도 증가
	}

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}