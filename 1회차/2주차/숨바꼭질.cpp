// 백준 1697번 문제

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int board[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	fill(board, board+100001, -1);

	board[n] = 0; // 수빈 0
	// board[k] = -2; // 동생 -2
		// 오류의 원인
		// 이유는 아직 모르겠음
		// -2로 설정해놓고 while 조건을
		// board[k] == -2로 하면 틀림
		// 모르겠음...
		// n == k 일경우 n을 덮어쓰게됨....이것때문?

	queue<int> check_que;
	check_que.push(n);

	while(board[k] == -1)
	{
		int select = check_que.front();
		check_que.pop();
		
		for (int nx : {select - 1, select + 1, select * 2})
		{
			if (nx < 0 || nx > 100000) continue; // 탐색하려는 인덱스를 벗어남
			if (board[nx] >= 0) continue; // 시작점 or 이미 탐색함
			board[nx] = board[select] + 1;
			check_que.push(nx);
		}
	}
	cout << board[k];
}