// 백준 1620번 문제

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> name_to_idx;
	vector<string> idx_to_name;
	string name;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> name;
		name_to_idx[name] = i;
		idx_to_name.push_back(name);
	}

	string question;
	int nb;
	while (m--)
	{
		cin >> question;
		if (isdigit(question[0]))
		{
			nb = stoi(question);
			cout << idx_to_name[nb - 1] << '\n';
		}
		else
			cout << name_to_idx[question] << '\n';
	}
}