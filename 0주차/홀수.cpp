#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 2576번 문제

int main()
{
	vector<int> odds;
	int n, add = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> n;
		if (n % 2 != 0)
			odds.push_back(n);
	}
	if (odds.size() > 0)
	{
		sort(odds.begin(), odds.end());
		for (int i = 0; i < odds.size(); i++)
			add += odds[i];
		cout << add << '\n' << odds[0];
	}
	else
		cout << -1;
}