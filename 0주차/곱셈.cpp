#include <iostream>
using namespace std;

// 백준 2588번 문제

int main()
{
	int a;
	int b;
	int mod1;
	int mod2;
	int mod3;
	int total;
	
	cin >> a;
	cin >> b;
	mod1 = a * (b % 10);
	b /= 10;
	mod2 = a * (b % 10);
	b /= 10;
	mod3 = a * b;
	total = mod1 + (mod2 * 10) + (mod3 * 100);
	cout << mod1 << endl;
	cout << mod2 << endl;
	cout << mod3 << endl;
	cout << total;
	return 0;
}