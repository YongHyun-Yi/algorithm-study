#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 2309번 문제

int main()
{
	int n, add = 0, flag = 0;
	vector<int> heights;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		heights.push_back(n);
		add += n;
	}
	for (int i = 0; i < 9 - 1; i++)
	{
		if (flag)
			break;
		for (int j = i + 1; j < 9; j++)
		{
			if (add - (heights[i] + heights[j]) == 100)
			{
				heights.erase(heights.begin() + j);
				heights.erase(heights.begin() + i);
				flag = 1;
				break;
			}
		}
	}
	sort(heights.begin(), heights.end());
	for (int i = 0; i < 7; i ++)
		cout << heights[i] << '\n';
}