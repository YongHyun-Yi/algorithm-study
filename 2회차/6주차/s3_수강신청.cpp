// 백준 13414번 문제

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> check;
	vector<string> vec(500000);
	int n, m;
	cin >> n >> m;

	string nb;
	for (int i = 0; i < m; i++)
	{
		cin >> nb;
		if (check.find(nb) != check.end())
			vec[check[nb]] = " ";
		vec[i] = nb;
		check[nb] = i;
		
	}

	for (auto result : vec)
	{
		if (!n)
			break;

		if (result != " ")
		{
			cout << result << '\n';
			n--;
		}
	}
}