#include <iostream>

using namespace std;

// inspace sort 풀이

int arr[1000000];

void quick_sort(int start, int end)
{
	if (end - start <= 1) return;

	// left 포인터와 right 포인터를 둔다
	int pivot = arr[start];
	int *left = arr + start + 1;
	int *right = arr + end - 1; // 맨 마지막 요소는 사이즈 - 1로 가리킨다 stl의 배열관련 함수들은 마지막 범위를 포함하지 않기때문에 사이즈만큼을 인자에 그대로 넘겨줘서 헛갈렸음

	int pivot_index;
	while (1)
	{
		int temp;

		while (*left <= pivot) left++;
		while (*right > pivot) right--;

		if (left >= right)
		{
			temp = *right;
			*right = pivot;
			arr[start] = temp;
			pivot_index = right - arr;
			break;
		}

		temp = *right;
		*right = *left;
		*left = temp;
	}

	quick_sort(start, pivot_index);
	quick_sort(pivot_index + 1, end);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	quick_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}

// temp배열을 사용하는 풀이

// int arr[4] = {4, 2, 3, 1};
// int temp[4];

// void quick_sort(int start, int end)
// {
// 	if (end - start <= 1) return;

// 	int pivot = arr[start];
// 	int temp_index = 0;

// 	for (int i = start + 1; i < end; i++)
// 		if (arr[i] <= pivot) temp[temp_index++] = arr[i];
	
// 	temp[temp_index++] = pivot;
// 	int pivot_index = temp_index;

// 	for (int i = start + 1; i < end; i++)
// 		if (arr[i] > pivot) temp[temp_index++] = arr[i];
	
// 	for (int i = start; i < end; i++) arr[i] = temp[i];

// 	quick_sort(start, pivot_index);
// 	quick_sort(pivot_index + 1, end);
// }

// int main()
// {
// 	int n;
// 	cin >> n;
// for (int i = 0; i < n; i++) cin >> arr[i];

// 	quick_sort(0, n);

// 	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
// }