// 백준 7785번 문제

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	unordered_set<string> input;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;

		if (state == "enter")
			input.insert(name);
		else
			input.erase(name);
	}

	vector<string> sorted_name(input.begin(), input.end());

	sort(sorted_name.begin(), sorted_name.end(), greater<string>());

	for (auto str : sorted_name)
		cout << str << '\n';
}