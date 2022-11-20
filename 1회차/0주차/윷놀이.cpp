#include <iostream>
#include <vector>
using namespace std;

// 백준 2490번 문제

int main()
{
	int n;
	for (int i = 0; i < 3; i++)
	{
		vector<int> a(2);
		for (int j = 0; j < 4; j++)
		{
			cin >> n;
			a[n]++;
		}
		if (a[1] == 4)
			cout << "E";
		else
			if (a[0] == 4)
				cout << "D";
			else if (a[0] == 3)
				cout << "C";
			else if (a[0] == 2)
				cout << "B";
			else if (a[0] == 1)
				cout << "A";
		cout << "\n";
	}
}