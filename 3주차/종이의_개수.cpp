// 백준 1780번 문제

#include <iostream>

using namespace std;

int minus_one = 0, zero = 0, one = 0, paper[2187][2187];

bool serch(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[i][j] != paper[x][y]) // 선택지점이 시작지점과 값이 다르면
				return false; // 즉시 종료하고 false를 반환
	return true; // 끝까지 돌면 true를 반환
}

void rec(int n, int x, int y)
{
	if (serch(n, x, y))
	{
		if (paper[x][y] == -1) minus_one++;
		else if (paper[x][y] == 0) zero++;
		else one++;
		return ;
	}
	n /= 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			rec(n, x + i * n, y + j * n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	rec(n, 0, 0);
	cout << minus_one << '\n' << zero << '\n' << one;
}

// 주어진 그리드를 탐색
// 틀린값이 하나라도 나오면 나눠서 재귀
// 틀린값이 하나도 없으면 변수에 1 더하고 끝
// n == 1 이면 그냥 바로 값 더하고 끝 -> 그냥 1일때도 탐색이 똑같이 적용됨