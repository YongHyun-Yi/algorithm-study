#include <iostream>
using namespace std;

// ���� 1330�� ����

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