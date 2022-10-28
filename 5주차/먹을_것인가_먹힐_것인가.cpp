// 백준 7795번 문제

#include <iostream>

using namespace std;

int arr_a[20000];
int arr_b[20000];
int temp[20000];

void merge(int start, int end, int *arr)
{
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

void merge_sort(int start, int end, int *arr)
{
	if (end == start + 1) return;

	int mid = (start + end) / 2;
	merge_sort(start, mid, arr);
	merge_sort(mid, end, arr);
	merge(start, end, arr);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while(t--)
	{
		int result = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> arr_a[i];
		merge_sort(0, n, arr_a);

		for (int i = 0; i < m; i++) cin >> arr_b[i];
		merge_sort(0, m, arr_b);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr_a[i] <= arr_b[j]) continue;
				result++;
			}
		}

		cout << result << '\n';
	}
}

// 정렬없이 이중반복문으로도 풀 수 있지만
// 그렇게 제출하면 시간초과가 나는 문제
// 정렬시켜놓으면 앞의 필요없는 케이스를 바로 continue로 건너뛸수있다