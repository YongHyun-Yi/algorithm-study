// 백준 2448번 문제

#include <iostream>

using namespace std;

char board[1024 * 3][1024 * 3 * 2 - 1]; // x는 3만큼 필요할떄 y는 3 * 2 - 1인 5만큼 필요하기때문

void rec(int n, int x, int y)
{
	if (n == 3)
	{
		board[x][y] = '*';
		board[x + 1][y - 1] = '*';
		board[x + 1][y + 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
			board[x + 2][i] = '*';
		
		return;
	}

	int new_n = n / 2; // 아마도 3 * 2^k 라서 축소할때 n과 비례하는 2를 줄여나가는것으로 보임
	rec(new_n, x, y);
	rec(new_n, x + new_n, y - new_n);
	rec(new_n, x + new_n, y + new_n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rec(n, 0, n - 1); // 3으로 시작하면 n - 2 즉 0, 2에 첫 별이 찍힌다

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++) // 중심점은 n * 2가 되지만 0부터 세니까 -1 해준다
			if (board[i][j] == '*') cout << board[i][j];
			else cout << ' ';
		cout << '\n';
	}
}

// << 정답 코드보고 배운것 >>
// 재귀로 출력을 실시간으로 하는게 아니라
// 재귀로 문자열을 조작하고
// 출력은 한번에한다
// 실시간으로 출력은 어떤식으로 해야하지...?