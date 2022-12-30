// 백준 2805번 문제

#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long trees[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> trees[i];
	
	long long start_idx = 1, end_idx = *max_element(trees, trees + n), result = 0;
	while (start_idx <= end_idx)
	{
		long long current_m = 0;
		long long mid_idx = (start_idx + end_idx) / 2;

		for (int i = 0; i < n; i++)
			if (trees[i] - mid_idx > 0)
			current_m += trees[i] - mid_idx;
		
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