// 백준 16401번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int candies[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> candies[i];
	
	sort(candies, candies + n);
	
	int start_idx = 1, end_idx = *max_element(candies, candies + n), result = 0;
	while (start_idx <= end_idx)
	{
		int current_m = 0;
		int mid_idx = (start_idx + end_idx) / 2;

		for (int i = 0; i < n; i++)
			current_m += candies[i] / mid_idx;
		
		if (current_m < m)
			end_idx = mid_idx - 1;
		else
		{
			result = mid_idx;
			start_idx = mid_idx + 1;
		}
	}

	cout << result;
}
