// 백준 15683번 문제

#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m, mn = 0;
int office[8][8], board[8][8];
vector<pair<int, int>> cctv;
vector<pair<int, int>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void check_area(int x, int y, int dir)
{
	dir %= 4;

	while(1)
	{
		x += dxy[dir].X;
		y += dxy[dir].Y;

		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) return;
		if (board[x][y] != 0) continue;

		board[x][y] = 7;
	}
}

void rec(int k) // k번째 카메라, 수열구하듯이 자신의 경우의 수를 하나씩 배열에 넣어보고 다음 k + 1번째 카메라를 체크한다
{
	if (k == cctv.size())
	{
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val += (board[i][j] == 0);
		mn = min(mn, val);
		return;
	}

	int x = cctv[k].X;
	int y = cctv[k].Y;
	int cctv_dir = board[x][y];

	for (int dir = 0; dir < 4; dir++)
	{
		int backup[8][8]; // is_used 와 비슷한 용도로 사용되는 변수
		copy(&board[0][0], &board[0][0] + 8 * 8, &backup[0][0]);

		switch (cctv_dir)
		{
			case 1:
				check_area(x, y, dir);
				break;
			
			case 2:
				check_area(x, y, dir);
				check_area(x, y, dir + 2);
				break;
			
			case 3:
				check_area(x, y, dir);
				check_area(x, y, dir + 1);
				break;
			
			case 4:
				check_area(x, y, dir);
				check_area(x, y, dir + 1);
				check_area(x, y, dir + 2);
				break;
			
			case 5:
				check_area(x, y, dir);
				check_area(x, y, dir + 1);
				check_area(x, y, dir + 2);
				check_area(x, y, dir + 3);
				break;
		}

		rec(k + 1);

		copy(&backup[0][0], &backup[0][0] + 8 * 8, &board[0][0]);
			// is_used = true <-
			// 재귀(k + 1)
			// is_used = false <-
			//
			// 이 패턴을 구현하기위한 backup[8][8]
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6) cctv.push_back({i, j});
			if (office[i][j] == 0) mn++;
		}
	}

	copy(&office[0][0], &office[0][0] + 8 * 8, &board[0][0]);

	rec(0);

	cout << mn;
}