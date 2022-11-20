// 백준 1941번 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

bool is_selected[25]; // 뽑아낸 조합
char classroom[5][5];
int result = 0;

vector<pair<int, int>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> classroom[i][j];
	
	fill(is_selected + 7, is_selected + 25, true); // false 일때만 선택한다, 초기값 세팅

	do
	{
		queue<pair<int, int>> bfs_que;
		bool visit[5][5] = {};
		for (int i = 0; i < 25; i++) // 학생을 1차원 배열로 -> next_permutation 때문인것같음, 얘는 2차원배열 어떻게 넣을지 모르겠음
		{
			int x = i / 5; // 늦게 도는 인덱스는 '/'로
			int y = i % 5; // 빨리 도는 인덱스는 '%'로 표현
			if (!is_selected[i] && bfs_que.empty()) // 선택되어있으면 queue에 넣고 bfs 시작, 첫 시작요소만 넣고 해야함, 나머지 요소들이 인접한지 확인
			{
				visit[x][y] = true;
				bfs_que.push({x, y});
			}
			// queue.empty() 조건을 빼먹어서 넣는 요소마다 adj++ 이 되어버려서 인접한지는 알수없으나
			// 다솜파가 4개 이상인 경우 pass가 되었음;
			// 문제 자체의 오류인듯

			int adj = 0, dasom = 0; // 현재 인접한 요소 갯수, 다솜파의 수
			while (!bfs_que.empty())
			{
				pair<int, int> select = bfs_que.front();
				bfs_que.pop();

				adj++; // 유효한 요소만 들어갔으니 pop할때마다 인접한 요소의 수를 올린다
				dasom += (classroom[select.X][select.Y] == 'S'); // 갯수세기는 이런식으로도 계산할수있다
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = select.X + dxy[dir].X;
					int ny = select.Y + dxy[dir].Y;

					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visit[nx][ny] || is_selected[(nx * 5) + ny]) continue; // 범위밖 or 이미 방문 or 뽑아놓은 조합이 아니면 continue

					bfs_que.push({nx, ny});
					visit[nx][ny] = true;
				}
			}

			result += (adj >= 7 && dasom >= 4); // 뽑아놓은 조합이 모두 인접한 요소이고 다솜파가 4명이상이면 result++
		}
	}
	while(next_permutation(is_selected, is_selected + 25)); // 다음 조합을 뽑아준다, 개날먹

	cout << result;
}

// https://www.acmicpc.net/source/50746721 << 80초 걸린 풀이, 차이점은 무엇인지...?
// << 정답코드보고 배운것 >>
//
// dfs로 조합을 뽑아내고 bfs로 인접한지를 검사하고 다솜파를 세는것
// 이 로직은 똑같으나 조합을 뽑아내는 dfs부분을
// algorithm 헤더의 next_permutation 함수로 날먹함
// next_permutation 는 do while의 형식을 띄고있음
// 첫조합을 세팅하고 해당조합을 사용하고 next_permutation를 while문에서
// 사용하면서 유효성을 검사함
// 뽑아낸 조합으로 bfs를 돌리고 다솜파의 수를 세기만 하면 됨
// next_permutation 함수에 익숙해지면 조합문제가 쉬워질수도...
// ------------------------
// '순열'과 '조합'을 의식할것
// 둘은 다른것
// 모든 조합을 뽑아내고 인접한지 bfs로 검사하기
// 처음부터 인접한 조합을 뽑아낼수야 있겠지만
// 아직은 버겁기도 하고 괜히 어렵게 생각하게되버림
// 조합으로 쓸 크기7의 배열에 요소를 넣고
// 각 요소마다 좌표계산을 해서 인접한지 계산하고 아니면 continue 할수있을것
// 요소의 갯수와 인접하다는 조건이 확인되면 이다솜파의 수를 셈
// 이다솜파의 수도 통과하면 ans++ 해줌