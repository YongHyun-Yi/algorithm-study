// 백준 5397번 문제

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	int t;
	string str;

	cin >> t;
	while (t)
	{
		list<char> password;
		auto cursor = password.end();

		cin >> str;
		for (char c : str)
		{
			if (c == '<')
			{
				if (cursor != password.begin())
					cursor--;
			}
			else if (c == '>')
			{
				if (cursor != password.end())
					cursor++;
			}
			else if (c == '-')
			{
				if (cursor != password.begin())
				{
					cursor--;
					cursor = password.erase(cursor);
				}
			}
			else
				password.insert(cursor, c);
		}
		for (auto i : password)
			cout << i;
		cout << '\n';
		t--;
	}
}