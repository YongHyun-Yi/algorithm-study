#include <iostream>
using namespace std;

// 백준 2525번 문제

int main()
{
	int h;
	int m;
	int duration;
	cin >> h >> m;
	cin >> duration;

	m += duration;
	h += m / 60;
	m = m % 60;
	
	if (h >= 24)
		h = h - 24;
	cout << h << " " << m;
}