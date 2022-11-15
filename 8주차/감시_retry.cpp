// 백준 15683번 문제

#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

int n, m; // 다른 함수에서도 n m 을 가지고 반복문을 돌려야함
int board[8][8];
int copy_board[8][8];
vector<pair<int, int>> cctv_pos;
pair<int, int> dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void check_area(int dir, int pos_x, int pos_y)
{
	dir %= 4;

	while(1)
	{
		pos_x += dxy[dir].X;
		pos_y += dxy[dir].Y;
			// 바라보는 방향으로 진행
		if (pos_x < 0 || pos_x >= n || pos_y < 0 || pos_y >= m || copy_board[pos_x][pos_y] == 6) break;
		if (copy_board[pos_x][pos_y] != 0) continue; // 벽은 위에서 스킵되고 카메라는 덮어씌우면 다음 cctv check에서 문제가 생김

		copy_board[pos_x][pos_y] = 7;
	}
}

int check_cctv(int current_bf)
{
	for (int i = 0; i < cctv_pos.size(); i++)
	{
		int dir = current_bf % 4;
		current_bf /= 4;

		switch (board[cctv_pos[i].X][cctv_pos[i].Y])
		{
			case 1:
				check_area(dir, cctv_pos[i].X, cctv_pos[i].Y);
				break;
			
			case 2:
				check_area(dir, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 2, cctv_pos[i].X, cctv_pos[i].Y);
				break;
			
			case 3:
				check_area(dir, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 1, cctv_pos[i].X, cctv_pos[i].Y);
				break;
			
			case 4:
				check_area(dir, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 1, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 2, cctv_pos[i].X, cctv_pos[i].Y);
				break;
			
			case 5:
				check_area(dir, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 1, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 2, cctv_pos[i].X, cctv_pos[i].Y);
				check_area(dir + 3, cctv_pos[i].X, cctv_pos[i].Y);
				break;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += (copy_board[i][j] == 0);
	
	return (cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int min_area = 0;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) cctv_pos.push_back({i, j});
			else if (board[i][j] == 0) min_area++; // 카메라가 0개인경우를 대비해서
		}
	}

	int end_of_bf = 1; // cctv가 0개일때 무조건 한 번 돌게되어있지만 딱히 걱정할 필요없음, 체크할 cctv가 없으니 보드는 그대로임
	for (int i = 0; i < cctv_pos.size(); i++) // 부동소수점 이슈를 피하기위한 직접 곱하기
		end_of_bf *= 4;

	for (int current_bf = 0; current_bf < end_of_bf; current_bf++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				copy_board[i][j] = board[i][j];
		min_area = min(min_area, check_cctv(current_bf));
	}
	
	cout << min_area;
}

// 카메라 위치 저장
// 경우의 수를 4진수로 나눠서 받음 -> 천천히 도는건 /연산 빨리 도는건 % 연산
// 0 ~ 4 : 바라보는 방향을 나타냄
// 카메라 위치를 저장한 배열을 for문으로 돌면서
// 경우의 수를 4진수 4자리수로 만들어 매칭시킴
// board 배열을 복사하고 위에서 매칭시킨 카메라로
// 반복문을 돌려서 감시하고잇는 부분의 값을 7로 바꿈
// 0 : 그냥 땅 1 ~ 5 : 카메라 6 : 벽
// 보드판에서 7의 개수를 세고 변수에 저장할때 min 함수를 사용해서 저장