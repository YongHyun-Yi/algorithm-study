// 백준 1600번 문제

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define get_x(selected_tuple) get<0>(selected_tuple)
#define get_y(selected_tuple) get<1>(selected_tuple)
#define get_cnt(selected_tuple) get<2>(selected_tuple)
using namespace std;

int k, w, h;
int board[200][200];
int dis[200][200][30];
queue<tuple<int, int, int>> check_que;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			for (int z = 0; z < k; z++)
				dis[i][j][z] = -1;
	
	for (int z = 0; z < k; z++)
		dis[0][0][z] = 1;
	
	check_que.push({0, 0, 0});
	while (!check_que.empty())
	{
		tuple<int, int, int> select = check_que.front();
		check_que.pop();

		// if (get_cnt < k)
		if (get_x(select) == h - 1 && get_y(select) == w - 1)
			cout << dis[get_x(select)][get_y(select)][get_cnt(select)];
	}
	cout << "-1";
}