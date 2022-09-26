#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 2752번 문제

int main()
{
	vector<int> a(3);
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < 3; i++)
		cout << a[i] << ' ';
}