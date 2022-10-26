// 백준 11652번 문제

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100000];

void merge(int start, int end)
{
	long long temp[100000];

	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;

	for (int i = start; i < end; i++)
	{
		if (start_index == mid) temp[i] = arr[mid_index++];
		else if (mid_index == end) temp[i] = arr[start_index++];
		else if (arr[start_index] <= arr[mid_index]) temp[i] = arr[start_index++];
		else temp[i] = arr[mid_index++];
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

	int mx_cnt = 0, cnt = 1;
	long long mx_nb;
		// 최대갯수, 현재갯수, 최대갯수를 가진 숫자
	
	int index = 0;
	while (index < n - 1)
	{
		while (arr[index] == arr[index + 1])
		{
			index++;
			cnt++;
		}
		
		if (cnt > mx_cnt)
		{
			mx_cnt = cnt;
			mx_nb = arr[index];
		}

		cnt = 1;
		index++;
	}

	cout << mx_nb;
}