#include <iostream>
using namespace std;

// ���� 10952�� ����

int main()
{
	int a, b;
	cin.tie(NULL);
	cin >> a >> b;
	while (a > 0 && b > 0)
	{
		cout << a + b << "\n";
		cin >> a >> b;
	}
	return 0;
}