// 백준 10866번 문제

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int MX = 10000;
	int n, head = MX, tail = MX, deq[2*MX + 1];
	cin >> n;
	while(n--)
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		string cmd;
		cin >> cmd;

		if (cmd == "push_front")
		{
			int x;
			cin >> x;
			deq[--head] = x;
		}
		else if (cmd == "push_back")
		{
			int x;
			cin >> x;
			deq[tail++] = x;
		}
		else if (cmd == "pop_front")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
				cout << deq[head++] << '\n';
		}
		else if (cmd == "pop_back")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
				cout << deq[--tail] << '\n';
		}
		else if (cmd == "size")
			cout << tail - head << '\n';
		else if (cmd == "empty")
			cout << (head == tail ? 1 : 0) << '\n';
		else if (cmd == "front")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
				cout << deq[head] << '\n';
		}
		else if (cmd == "back")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
				cout << deq[tail - 1] << '\n';
		}
	}
}