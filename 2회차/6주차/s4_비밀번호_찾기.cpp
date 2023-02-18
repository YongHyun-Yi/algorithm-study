// 백준 17219번 문제

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, string> input;
	int n, m;
	cin >> n >> m;

	string site, id;
	while (n--)
	{
		cin >> site >> id;
		input[site] = id;
	}

	string question;
	while (m--)
	{
		cin >> question;
		cout << input[question] << '\n';
	}
}