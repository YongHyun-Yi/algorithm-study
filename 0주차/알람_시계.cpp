#include <iostream>
using namespace std;

// 백준 2884번 문제

int main()
{
	int h;
	int m;
	cin >> h;
	cin >> m;
	if (m >= 45 )
		m -= 45;
	else
	{
		m = 60 - (45 - m);
		h -= 1;
	}
	if (h < 0)
		h = 23;
	cout << h << " " << m;
}