#include <iostream>
#include <algorithm>
using namespace std;

// 백준 10808번 문제

int main()
{
	int arr[26];
	fill(arr, arr+26, 0);
	string str;
	cin >> str;
	for (char c : str)
		arr[c - 'a']++;
	for (int a : arr)
		cout << a << " ";
	return 0;
}