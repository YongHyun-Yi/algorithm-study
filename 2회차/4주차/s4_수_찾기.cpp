// 백준 1920번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> src; // 처음 채우는 배열

int binary_search(int tofind)
{
	int start_index = 0;
	int end_index = n - 1;

	while (start_index <= end_index)
	{
		int mid_index = (start_index + end_index) / 2;

		if (src[mid_index] > tofind)
			end_index = mid_index - 1;
		else if (src[mid_index] < tofind)
			start_index = mid_index + 1;
		else
			return (1);
	}
	return (0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		src.push_back(input);
	}

	sort(src.begin(), src.end());

	cin >> m;
	while (m--)
	{
		int tofind;
		cin >> tofind;
		cout << binary_search(tofind) << '\n';
	}
}