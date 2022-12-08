// 백준 1932번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int board[501][502];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> board[i][j];
			board[i][j] += max(board[i - 1][j - 1], board[i - 1][j]);
		}
	}

	cout << *max_element(&board[n][1], &board[n][n + 1]);
		// 0번부터세면 n ~ n + size가 맞지만 1부터 세기때문에 시작도 n + 1이고 끝지점도 n + size + 1 이 된다...?
		// 두번째 인자를 end로 받는거보면 얘도 마지막은 포함이 안되나...?
}