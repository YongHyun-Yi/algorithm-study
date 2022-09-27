// 백준 10828번 문제

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, nb, pos = 0;
	int st[10001];
	string cmd;

	cin >> n;
	while (n)
	{
		cin >> cmd;

		if (cmd == "top")
		{
			if (pos == 0)
				cout << -1 << '\n';
			else
				cout << st[pos - 1] << '\n';
		}
		else if (cmd == "pop")
		{
			if (pos == 0)
				cout << -1 << '\n';
			else
			{
				cout << st[pos - 1] << '\n';
				pos--;
			}
		}
		else if (cmd == "empty")
		{
			if (pos == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "size")
			cout << pos << '\n';
		else if (cmd == "push")
		{
			cin >> nb;
			st[pos] = nb;
			pos++;
		}

		n--;
	}
}