// 백준 1406번 문제

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	string str;
	list<char> ls;
	int m;
	cin >> str;
	for (char c : str)
		ls.push_back(c);
	auto cursor = ls.end();
	cin >> m;
	char cmd;
	while (m)
	{
		cin >> cmd;
		if (cmd == 'L' && cursor != ls.begin())
			cursor--;
		else if (cmd == 'D' && cursor != ls.end())
			cursor++;
		else if (cmd == 'B' && cursor != ls.begin())
		{
			if (cursor != ls.begin())
			{
				cursor--;
				cursor = ls.erase(cursor);
			}
		}
		else if (cmd == 'P')
		{
			cin >> cmd;
			ls.insert(cursor, cmd);
		}
		m--;
	}
	for (auto i : ls)
		cout << i;
}