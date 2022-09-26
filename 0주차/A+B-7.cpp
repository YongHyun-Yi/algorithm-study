#include <iostream>
using namespace std;

// 백준 11021번 문제

int main()
{
	cin.tie(NULL);
	int t, i, a, b;
	cin >> t;
	i = 1;
	while (i <= t)
	{
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << '\n';
		i++;
	}
	return 0;
}