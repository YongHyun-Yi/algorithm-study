// 백준 1181번 문제

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[20000]; // using namespace std 위에 선언하면 string을 타입이름으로 인식하지 못하니 주의
string temp[20000];

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;
	
	for (int i = start; i < end; i++)
	{
		// cout << "arr[start index] : " << arr[start_index] << " arr[mid index] : " << arr[mid_index] << '\n';
		if (start_index == mid) temp[i] = arr[mid_index++];
		else if (mid_index == end) temp[i] = arr[start_index++];
		else if (arr[start_index].length() < arr[mid_index].length()) temp[i] = arr[start_index++];
		else if (arr[start_index].length() > arr[mid_index].length()) temp[i] = arr[mid_index++];
		else
		{
			// 철자마다 아스키코드값 비교
			int cmp_index = 0;
			while (arr[start_index][cmp_index] == arr[mid_index][cmp_index] && (arr[start_index][cmp_index] && arr[mid_index][cmp_index])) cmp_index++; // char 자료형을 비교, 길이가 짧으면 null인 0을 반환할테니 비교가능
				// 두 문자가 완전히 같을경우 null을 만나고 다음 인덱스까지 잘못 참조해버릴수있으니 &&로 두 문자가 모두 null이 아닐때를 추가해야함

			if (arr[start_index][cmp_index] <= arr[mid_index][cmp_index]) temp[i] = arr[start_index++];
			else temp[i] = arr[mid_index++];
		}
	}

	for (int i = start; i < end; i++) arr[i] = temp[i];
}

void merge_sort(int start, int end)
{
	if (end == start + 1) return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(0, n);

	string check = "";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != check) cout << arr[i] << '\n';
		check = arr[i];
	}
}
// 우선순위
// 1. 길이가 짧은것
// 2. 사전순
// strcmp랑 비슷하게 -> 글자길이가 다른데도 철자가 우선인애가 먼저와버림

// 놓친조건
// 중복되는 단어는 한번만 표기