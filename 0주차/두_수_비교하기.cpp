#include <iostream>
using namespace std;

// 백준 1330번 문제

int main()
{
	int a;
	int b;
	cin >> a >> b;
	if (a > b)
		cout << ">";
	else if (a < b)
		cout << "<";
	else
		cout << "==";
	return 0;
}