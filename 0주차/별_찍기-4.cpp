#include <iostream>
using namespace std;

// ���� 2441�� ����

int main()
{
	int n;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j >= n)
				cout<< "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}