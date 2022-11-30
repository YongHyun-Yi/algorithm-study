// 백준 3211번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		if (i >= vec[i])
		{
			cout << i + 1;
			return 0;
		}
	}
}