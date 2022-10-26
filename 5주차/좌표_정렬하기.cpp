//백준 11650번 문제

#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int, int>> vec;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
		cout << vec[i].X << ' ' << vec[i].Y << '\n';
}