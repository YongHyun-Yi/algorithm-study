#include <iostream>
using namespace std;

// 백준 3003번 문제

int main()
{
	int pices[6];
	cin >> pices[0] >> pices[1] >> pices[2] >> pices[3] >> pices[4] >> pices[5];
	cout << 1 - pices[0] << " " << 1 - pices[1] << " " << 2 - pices[2] << " " << 2 - pices[3] << " " << 2 - pices[4] << " " << 8 - pices[5];
	return 0;
}