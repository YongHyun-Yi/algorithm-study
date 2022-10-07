#include <iostream>
using namespace std;

// 백준 2446번 문제

int main()
{
	int n, center;
	cin >> n;
	center = ((2 * n - 1) / 2 + 1);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= center + i; j++)
		{
			if ((j >= center - i) && (j <= center + i))
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= center + i; j++)
		{
			if ((j >= center - i) && (j <= center + i))
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}