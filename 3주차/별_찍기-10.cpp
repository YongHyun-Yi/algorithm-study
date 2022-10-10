// 백준 2447번 문제

#include <iostream>

using namespace std;

void rec(int n, int x, int y)
{
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1) // 현재 보고있는칸 확인
		cout << ' ';
	else
	{
		if (n / 3 == 0) cout << '*';
		else rec(n / 3, x, y);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rec(n, i, j);
		}
		cout << '\n';
	}
}

// << 정답 코드보고 배운것 >>
