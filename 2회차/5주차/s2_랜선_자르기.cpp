// 백준 1654번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
unsigned int lines[10000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> lines[i];
	
	sort(lines, lines + k);
	
	unsigned int start_idx = 1, end_idx = *max_element(lines, lines + k), result = 0;
	while (start_idx <= end_idx)
	{
		int current_n = 0;
		unsigned int mid_idx = (start_idx + end_idx) / 2;

		for (int i = 0; i < k; i++)
			current_n += lines[i] / mid_idx;
		
		if (current_n < n)
			end_idx = mid_idx - 1;
		else
		{
			result = mid_idx;
			start_idx = mid_idx + 1;
		}
	}

	cout << result;
}