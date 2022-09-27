//백준 18258번 문제

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, front = 0, back = 0, que[2000001];

	cin >> n;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int nb;
			cin >> nb;
			que[back++] = nb;
		}
		else if (cmd == "pop")
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
				cout << que[front++] << '\n';
		}
		else if (cmd == "size")
			cout << back - front << '\n';
		else if (cmd == "empty")
			if (back - front == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (cmd == "front")
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
				cout << que[front] << '\n';
		}
		else if (cmd == "back")
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
				cout << que[back - 1] << '\n';
		}
	}
}