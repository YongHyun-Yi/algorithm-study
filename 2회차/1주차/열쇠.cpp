// 백준 9328번 문제

#include <iostream>
#include <algorithm>
#include <queue>
#include <cctype>

#define X first
#define Y second

using namespace std;

int h, w, docu_cnt;
string board[100];
string inven;
bool visit[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> check_que;

bool oob(int nx, int ny)
{
	if (nx < 0 || nx >= h || ny < 0 || ny >= w) return true;
	else return false;
}

bool have_key(char key)
{
	if (isupper(key)) key = tolower(key);
	return ((inven.find(key) != string::npos));
}

bool is_door(char target)
{
	return (isupper(target));
}

bool is_key(char target)
{
	return (islower(target));
}

void bfs_init()
{
	for (int i = 0; i < h; i++) // 초기화 및 스타트지점 세팅
	{
		for (int j = 0; j < w; j++)
		{
			if ((i == 0 || i == h - 1) || (j == 0 || j == w - 1)) // 외곽부분 검사
			{
				if (board[i][j] == '$') // 출발지점에 서류가 있는 케이스를 생각못했음...
				{
					docu_cnt++;
					board[i][j] = '.';
				}
				else if (is_key(board[i][j])) // 출발지점에 열쇠가 있는 케이스도 생각을 못했음...
				{
					if (!have_key(board[i][j]))
						inven.push_back(board[i][j]);
					board[i][j] = '.';
				}
				else if (is_door(board[i][j]) && have_key(board[i][j])) // 시작지점이 문이고 열쇠를 가지고있는 경우
					board[i][j] = '.';
				
				if (board[i][j] == '.') // 시작지점이 빈칸인 경우
				{
					visit[i][j] = true;
					check_que.push({i, j});
				}
			}
			else
				visit[i][j] = false; // visit 초기화
		}
	}
}

void bfs()
{
	bool _new_key = false;

	bfs_init();

	while (check_que.size())
	{
		pair<int, int> select = check_que.front();
		check_que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = select.X + dx[dir];
			int ny = select.Y + dy[dir];

			if ((oob(nx, ny) || visit[nx][ny] || board[nx][ny] == '*')) continue; // 범위를 넘어갔거나 이미 방문했거나 벽인 경우

			if (board[nx][ny] == '$') // 서류를 발견한 경우
			{
				docu_cnt++;
				board[nx][ny] = '.';
			}
			else if (is_door(board[nx][ny])) // 문을 발견하고
			{
				if (have_key(board[nx][ny])) // 열쇠를 소지중인 경우
					board[nx][ny] = '.';
				else // 열쇠가 없는 경우
					continue;
			}
			else if (is_key(board[nx][ny])) // 열쇠를 발견하고
			{
				if (!have_key(board[nx][ny])) // 열쇠를 소지중이지 않은경우
				{
					inven.push_back(board[nx][ny]);
					_new_key = true;
				}
				board[nx][ny] = '.';
			}
			
			visit[nx][ny] = true;
			check_que.push({nx, ny});
		}
	}

	if (_new_key) bfs(); // 새 열쇠를 찾았으면 다시 탐색해본다
	else cout << docu_cnt << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			cin >> board[i];
		cin >> inven;

		if (inven == "0") inven.clear();
		docu_cnt = 0;

		bfs();
	}
}
// n회차를 돌리는 식으로
// dis를 매번 초기화
// 아이템을 먹으면 해당 칸은 빈칸으로 board를 수정
// bfs의 시작지점은 맵의 외곽에 벽이아닌곳