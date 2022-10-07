#include <iostream>
using namespace std;

// 백준 4344번 문제

int main()
{
	int c;
	double *arr, n, count, total;
	cin >> c;
	cout << fixed;
	cout.precision(3);
	while (c)
	{
		cin >> n;
		arr = (double *)malloc(sizeof(double) * n);
		
		total = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			total += arr[i];
		}
		total /= n;
		
		count = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > total)
				count++;
		}
		
		cout << count / n * 100 << '%' << '\n';
		
		c--;
	}
	return 0;
}