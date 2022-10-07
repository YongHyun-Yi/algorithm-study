#include <iostream>
using namespace std;

// 백준 10950번 문제

int main()
{
	int iteration, a, b, i;
	cin >> iteration;
	i = 0;
	while (i < iteration)
	{
		cin >> a >> b;
		cout << a + b << endl;
		i++;
	}
}