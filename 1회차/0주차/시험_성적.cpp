#include <iostream>
using namespace std;

// 백준 9498번 문제

int main()
{
	int scr;
	cin >> scr;
	
	if (scr >= 90)
		cout << "A";
	else if (scr >= 80 && scr < 90)
		cout << "B";
	else if (scr >= 70 && scr < 80)
		cout << "C";
	else if (scr >= 60 && scr < 70)
		cout << "D";
	else
		cout << "F";
	return 0;
}