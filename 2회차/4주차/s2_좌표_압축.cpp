// 백준 18870번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int input[1000000];
int sort_input[1000000];
int non_dup[1000000];
	// 입력순서로 출력을 해야되기 때문에 정렬용 배열을 따로 만들어준다...

int left_serch(int start_idx, int end_idx, int tofind)
{
	while (start_idx < end_idx)
	{
		int mid_idx = (start_idx + end_idx) / 2;
		
		if (non_dup[mid_idx] < tofind)
			start_idx = mid_idx + 1;
		else
			end_idx = mid_idx;
	}

	return (start_idx);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		sort_input[i] = input[i];
	}
	
	sort(sort_input, sort_input + n);

	int j = 0;
	for (int i = 0; i < n; i++)
		if (i == 0 || sort_input[i] != sort_input[i - 1])
			non_dup[j++] = sort_input[i];

	for (int i = 0; i < n; i++)
		cout << left_serch(0, j, input[i]) << ' ';
}