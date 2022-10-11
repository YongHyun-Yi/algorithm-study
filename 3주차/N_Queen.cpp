// 백준 9663번 문제

#include <iostream>

using namespace std;

int n, cnt = 0, board[15];

bool check_place(int x, int i) // 퀸의 공격범위에 닿는가?
{
	board[x] = i; // 우선 값을 대입하고 시작
	for (int i = 0; i < x; i++) // 이전에 넣어뒀던 값들과 비교해야하니 x보다 작은 인덱스만 탐색
	{
		if (board[x] == board[i] || abs(x - i) == abs(board[x] - board[i]))
			return false;
			// 배열의 인덱스가 x값 들어있는 값이 y값이 된다
			// 재귀를 반복할때마다 x + 1을 하니 x축은 겹칠일이 없지만
			// y끼리 겹치는지 확인을 위해 해당 배열에 들어있는 값을 비교
			// 대각선에 있는지는 두점사이의 기울기 구하는 공식을 활용
			// x1 - x2 와 y1 - y2 가 1이라면 정확히 대각선에 위치한게 된다
			// 둘중 하나라도 해당되면 false를 반환
	}
	return true;
}

void rec(int x)
{
	if (x == n) // 모든 배열에 퀸을 배치했으면 cnt를 올리고 이 재귀는 종료
	{
		cnt++;
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (check_place(x, i)) // (현재 배열 인덱스, 넣어볼 값) 현재 넣어볼값이 유효한지 체크
			rec(x + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rec(0);
	cout << cnt;
}