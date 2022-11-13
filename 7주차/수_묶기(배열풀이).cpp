// 백준 1744번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int pos_arr[50];
int neg_arr[50];

int main()
{
	int n, nb, pos_index = 0, neg_index = 0;
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nb;

		if (nb == 1) result++;
		else if (nb > 1) pos_arr[pos_index++] = nb;
		else neg_arr[neg_index++] = nb;
	}

	sort(pos_arr, pos_arr + pos_index);
	sort(neg_arr, neg_arr + neg_index);
		// arr + size 를 할때 그냥 참조하는거면 size부분이 인덱스처럼 0부터가 맞다
		// 근데 sort에 넣을때는 size부분이 포함되지 않으니 + 1된채로 쓰는게 맞다
	if (pos_index) pos_index--;
	if (neg_index) neg_index--;

	while (pos_index >= 1)
	{
		result += pos_arr[pos_index] * pos_arr[pos_index - 1];
		pos_index -= 2;
	}
	if (pos_index == 0) result += pos_arr[0];
	int end_index = neg_index; neg_index = 0; // 음수배열은 오름차순으로 계산해야되서 변수를 새로 옮겨담는다
	while (neg_index < end_index)
	{
		result += neg_arr[neg_index] * neg_arr[neg_index + 1];
		neg_index += 2;
	}
	if (neg_index == end_index) result += neg_arr[end_index];
	
	cout << result;
}
// -1 0 1 처럼 뒤에서 두개가 아니라 앞에서 두개를 골라야 하거나
// 1 1 처럼 0보다 크지만 곱하면 1이 되버리면 예외 처리를 해야함
// 근데 모르겟음...
//
// 스터디에서 같이 풀고 알게된것
// 그냥 노가다라고 생각이 들어도 시도해볼것
// 0은 따로 세서 음수랑 제거할 필요가없음 -> 음수끼리 곱하면 양수가됨
// 그냥 같이 넣어서 오름차순으로 처리해버리면 깔끔해짐
// 변수를 디테일하게 하나씩 만들지 않아도 됌
