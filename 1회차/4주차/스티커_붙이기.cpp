// 백준 18808번 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, r, c;
int board[40][40];
int sticker[10][10];

bool check_board(int x, int y)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sticker[i][j] == 1  && board[x + i][y + j] == 1) return false;
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sticker[i][j] == 1) board[x + i][y + j] = 1;
	
	return true;
}

void rotate_sticker()
{
	int temp[10][10];
	for (int j = 0; j < c; j++)
		for (int i = (r - 1); i >= 0; i--)
			temp[j][(r - 1) - i] = sticker[i][j];
	
	int temp2 = r;
	r = c;
	c = temp2;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sticker[i][j] = temp[i][j];
	
	// cout << "-------sticker---------\n";
	// for (int i = 0; i < r; i++)
	// {
	// 	for (int j = 0; j < c; j++)
	// 		cout << sticker[i][j] << ' ';
	// 	cout << '\n';
	// }
}

void check_sticker()
{
	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i <= n - r; i++) // n - r이 0일때도 한번은 실행되어야 함
			for (int j = 0; j <= m - c; j++)
				if (check_board(i, j)) return;
		rotate_sticker();
	}
}
// 스티커를 회전시키면 for 문의 제한범위인 r c 도 변경되야한다

int main()
{
	cin >> n >> m >> k;
	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];
		
		check_sticker();

		// cout << "-------board-------\n";
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 		cout << board[i][j] << ' ';
		// 	cout << '\n';
		// }
	}

	int val = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			val += (board[i][j] == 1);
	
	cout << val;
}

// 회전같은 경우에는 회전하기전의 배열과 회전후의 배열을
// 직접 그려보고나서 회전후의 배열에는 회전하기전의 배열에
// 매칭되는 좌표를 적어넣으면 규칙을 알아볼수있다
// 규칙을 파악해야함 << 중요!
//
// 예외조건을 통과하고나서 값을 넣어주는 작업을 하면
// 값을 넣으면서 체크하다가 예외가 나왔을때
// 다시 원상태로 되돌려야하는 작업을 안해줘도된다
// ------------------------------------------------
// board랑 비교하며 탐색
// sticker == 1 && sticker == board return false;
// board = 1;
// if false -> board 원위치, sticker 회전
//
// 회전은 어떻게? 똑같이 dx dy에서 인덱스로 사용?
// 격자에는 반드시 스티커가 한장이상 포함되도록 회전해야함
// 0 1 | 1 0 | 1 1 | 1 1
// 1 1 | 1 1 | 1 0 | 0 1
//
// 왼쪽에서 한칸씩 땡기는건
// for (int j = 0; j < m - c; j++) -> i, n도 똑같이
// x + i;
// 탐색을 모두 통과하면 종료
// 중간에 스티커가 겹치면 continue