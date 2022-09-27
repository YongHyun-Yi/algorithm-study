// 백준 10845번 문제

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, front = 0, back = 0;
	int que[10001];
	cin >> n;
	while (n)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int nb;
			cin >> nb;
			que[back] = nb;
			back++;
		}
		else if (str == "pop") // stack이랑은 다르게 맨 앞의 값을 빼고 맨 앞의 값을 출력해야함....
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
			{
				cout << que[front] << '\n';
				front++;
			}
		}
		else if (str == "size")
			cout << back - front << '\n';
		else if (str == "empty")
		{
			if (back - front == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front")
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
				cout << que[front] << '\n';
		}
		else if (str == "back")
		{
			if (back - front == 0)
				cout << -1 << '\n';
			else
				cout << que[back - 1] << '\n';
		}
		n--;
	}
}