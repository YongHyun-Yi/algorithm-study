// 백준 11651번 문제

#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.Y < b.Y) return true;

	else if (a.Y == b.Y)
		if (a.X < b.X) return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int, int>> vec;

	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++) cout << vec[i].X << ' ' << vec[i].Y << '\n';
}