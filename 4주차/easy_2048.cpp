// 백준 12100번 문제

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, mx = 0;
int board[20][20];
vector<pair<int, int>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // ↓ → ↑ ←


void check_line(int x, int y, int dir)
{
	deque<int> temp;
	bool add = true;
	int backup_x = x, backup_y = y;

	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		if (board[x][y] != 0)
		{
			if (!temp.empty())
			{
				if (board[x][y] == temp.back() && add)
				{
					temp.back() *= 2;
					add = false;
				}
				else
				{
					temp.push_back(board[x][y]);
					add = true;
				}
			}
			else temp.push_back(board[x][y]);
		}

		x += dxy[dir].X;
		y += dxy[dir].Y;
	}

	x = backup_x, y = backup_y;
	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		if (!temp.empty())
		{
			board[x][y] = temp.front();
			temp.pop_front();
		}
		else board[x][y] = 0;

		x += dxy[dir].X;
		y += dxy[dir].Y;
	}
}

void tilt_board(int dir)
{
	dir = (dir + 2) % 4;
	switch (dir)
	{
		case 0:
			for (int i = 0; i < n; i++)
				check_line(0, i, dir);
			break;
		
		case 1:
			for (int i = 0; i < n; i++)
				check_line(i, 0, dir);
			break;
		
		case 2:
			for (int i = 0; i < n; i++)
				check_line(n - 1, i, dir);
			break;
		
		case 3:
			for (int i = 0; i < n; i++)
				check_line(i, n - 1, dir);
			break;
	}
}

void rec(int k)
{
	if (k == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mx = max(mx, board[i][j]);
		return;
	}

	int backup[20][20];
	copy(&board[0][0], &board[0][0] + 20 * 20, &backup[0][0]); // is_used 같은 역할을 위한 backup, copy에서 버그가 자주 발생함...
	for (int i = 0; i < 4; i++)
	{
		tilt_board(i);

		rec(k + 1);

		copy(&backup[0][0], &backup[0][0] + 20 * 20, &board[0][0]); // 기울이기 전 배열로 원위치
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	rec(0);

	cout << mx;
}

// ** copy 함수를 사용할때 사이즈를 정확하게 입력하지 않으면 이상한 값이 들어가버리는 현상이 자주 나타남 **
// ** 넉넉하게 배열을 21까지 만들어놓고 copy는 20까지 했더니 오답이 출력됨 **
// ** 정확하게 만들어놓은 배열의 사이즈만큼을 다 copy해야 하는것같음 **
// ** 그냥 반복문 써서 덮어쓰는게 나을수도... **
// 5번 기울이는건 각 방향을 숫자로 생각할때 수열뽑아내듯이 하면...?
// /////////////////////////////////
// 판 기울이기
// ← 방향
// 0 2 0 2 4
//
// 4 4 0 0 0
// 열 - 1만큼 탐색
// 현재 열을 기준으로 또 탐색
// 현재 열이 0이 아닌경우
// 자신의 다음열부터 탐색해서 자신과 같은 요소를 찾으면
// 자신을 *2 하고 해당 요소를 0으로 변경 → 2 4 2 8 같은경우 4에 막혀야 하나 위와같이 탐색하면 뚫고 탐색을 해버림...
// 자신 다음요소부터 탐색해서 0이 아닐때까지 탐색
// 자신과 같으면 *2하고 해당요소를 0으로 변경
// 자신을 값이 0인 맨 왼쪽칸으로 위치시킴
// 중첩된 열 탐색을 3번을 하니 O(N^3)?
// 탐색방향은 판을 기울이는 방향의 반대방향 -> 카메라 문제에서 정반대 같은 경우는 dir, dir + 2로 나타내었음
//
// 0 2 0 2 4
// 0 2 0 2 / 까지만 for 반복문
// (0) -> 0이라서 continue
// (2) -> 두번째 2 까지만 체크
// *2를 하고 값이 0인 맨 왼쪽칸으로 이동
// (0) -> 0이라서 continue
// (2) -> 이미 앞에서 값을 곱하고 0이 되었으므로 continue, 불필요한 연산
//
// void pulling_line(int x, int y, int dir)
// {
// 	pair<int, int> nxy = {x, y};
// 	while (nxy.X>= 0 && nxy.X < n && nxy.Y >= 0 && nxy.Y < n)
// 	{
// 		//
// 	}
// }

// void check_line(int x, int y, int dir) // 시작점을 기준으로 해당 방향으로 모든 요소를 검사하면서 겹칠수있는게 있으면 겹친다, 정렬방향은?
// {
// 	while (x >= 0 && x < n && y >= 0 && y < n) // 이러면 가로로 검사하나 세로로 검사하나 하나만 끝까지 인덱스를 밀어도 끝남
// 	{
// 		if (board[x][y] != 0) // 선택한 요소가 0이라면 패스, return 해버리면 모든 요소를 다 함수를 불러야함, 좀 더 자동적으로 가능하게...
// 		{
// 			pair<int, int> nxy = {x, y};
// 			while(1)
// 			{
// 				nxy.X += dxy[dir].X;
// 				nxy.Y += dxy[dir].Y;

// 				if (nxy.X < 0 || nxy.X >= n || nxy.Y < 0 || nxy.Y >= n) break; // 탐색 범위를 벗어나면 while문 탈출
// 				if (board[nxy.X][nxy.Y] == 0) continue; // 0이 아닌 요소를 찾을때까지 탐색
				
// 				if (board[nxy.X][nxy.Y] == board[x][y]) // 비교후 *2하거나 그냥 패스
// 				{
// 					board[x][y] *= 2;
// 					board[nxy.X][nxy.Y] = 0;
// 				}

// 				break;
// 			}
// 		}
// 		x += dxy[dir].X;
// 		y += dxy[dir].Y; // 다음 요소를 선택후 탐색준비
// 	}
// }