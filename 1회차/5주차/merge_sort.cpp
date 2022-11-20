#include <iostream>

using namespace std;

int n;
int arr[1000000];
int temp[1000000];

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int start_index = start, mid_index = mid;
	for (int i = start; i < end; i++)
	{
		if (start_index >= mid) temp[i] = arr[mid_index++];
		else if (mid_index >= end) temp[i] = arr[start_index++];
		else if (arr[start_index] <= arr[mid_index]) temp[i] = arr[start_index++];
		else temp[i] = arr[mid_index++];
	}

	for (int i = start; i < end; i++) arr[i] = temp[i];
}

void merge_sort(int start, int end)
{
	if (end - start <= 1) return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}