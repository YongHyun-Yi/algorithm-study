// 백준 1074번 문제

#include <iostream>

using namespace std;

int rec(int n, int r, int c)
{
	if (n == 0) return 0;

	int half = 1 << (n - 1);
	if (r < half && c < half) return (rec(n - 1, r, c)); // 첫번쨰 사각형
	else if (r < half && c >= half) return (half * half + rec(n - 1, r, c - half)); // 두번쨰 사각형
	else if (r >= half && c < half) return (2 * half * half + rec(n - 1, r - half, c)); // 세번째 사각형
	else return (3 * half * half + rec(n - 1, r - half, c - half)); // 마지막 사각형
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	cout << rec(n, r, c);
}