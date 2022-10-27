// 백준 10825번 문제

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<string, int, int, int> arr[100000];
tuple<string, int, int, int> temp[100000];

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;

	for (int i = start; i < end; i++)
	{
		if (start_index == mid) temp[i] = arr[mid_index++];
		else if (mid_index == end) temp[i] = arr[start_index++];
		else
		{
			if (get<1>(arr[start_index]) > get<1>(arr[mid_index])) // 국어점수
				temp[i] = arr[start_index++];
			else if (get<1>(arr[start_index]) < get<1>(arr[mid_index]))
				temp[i] = arr[mid_index++];
			else
			{
				if (get<2>(arr[start_index]) < get<2>(arr[mid_index])) // 영어점수
					temp[i] = arr[start_index++];
				else if (get<2>(arr[start_index]) > get<2>(arr[mid_index]))
					temp[i] = arr[mid_index++];
				else
				{
					if (get<3>(arr[start_index]) > get<3>(arr[mid_index])) // 수학점수
						temp[i] = arr[start_index++];
					else if (get<3>(arr[start_index]) < get<3>(arr[mid_index]))
						temp[i] = arr[mid_index++];
					else // 이름 사전순
					{
						int cmp_index = 0;
						while ((get<0>(arr[start_index]))[cmp_index] == (get<0>(arr[mid_index])[cmp_index])) cmp_index++;
						
						if ((get<0>(arr[start_index]))[cmp_index] < (get<0>(arr[mid_index])[cmp_index]))
							temp[i] = arr[start_index++];
						else
							temp[i] = arr[mid_index++];
					}
				}
			}
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

	string name;
	int korean, english, math;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> korean >> english >> math;
		arr[i] = {name, korean, english, math};
	}
	
	merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << get<0>(arr[i]) << '\n';
}