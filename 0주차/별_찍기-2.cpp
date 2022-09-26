#include <iostream>
using namespace std;

// 백준 2439번 문제

int main()
{
	int n, i, j = 1;
	cin >> n;
	while (j <= n)
	{
		i = 1;
		while (i <= n)
		{
			if (n - i < j)
				cout << "*";
			else
				cout << " ";
			i++;
		}
		cout << "\n";
		j++;
	}
}