// 백준 1992번 문제

#include <iostream>

using namespace std;

char screen[64][64];

bool serch(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (screen[i][j] != screen[x][y])
				return false;
	return true;
}

void rec(int n, int x, int y)
{
	if (serch(n, x, y)) cout << screen[x][y];
	else
	{
		n /= 2;

		cout << '(';
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				rec(n, x + i * n, y + j * n);
		cout << ')';
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> screen[i][j];
	
	rec(n, 0, 0);
}

// 재귀를 부르기전에 ( 를 출력하고
// 재귀를 부르고나서 ) 를 출력함
// serch가 true면 해당 숫자를 출력