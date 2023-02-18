// 백준 18869번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> universe[50];

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int star_size;
			cin >> star_size;
			universe[i].push_back(star_size);
		}
	}

}