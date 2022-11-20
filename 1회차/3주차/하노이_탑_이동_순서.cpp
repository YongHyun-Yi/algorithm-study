// 백준 11729번 문제

#include <iostream>

using namespace std;

void rec(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return ;
	}
	rec(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	rec(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	rec(1, 3, n);
}