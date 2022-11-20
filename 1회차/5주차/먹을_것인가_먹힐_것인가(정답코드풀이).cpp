// 백준 7795번 문제

#include <iostream>
#include <algorithm>
#include <vector>

#define nb first
#define group second

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while(t--)
	{
		vector<pair<int, int>> vec;
		cin >> n >> m;

		int num_a;
		for (int i = 0; i < n; i++)
		{
			cin >> num_a;
			vec.push_back({num_a, 0}); // 숫자, 속해있는 그룹(0 - A, 1 - B) / 이러면 한 벡터에 다 섞어놓고 정렬해도 구별할수있다...
		}

		int num_b;
		for (int i = 0; i < m; i++)
		{
			cin >> num_b;
			vec.push_back({num_b, 1});
		}

		sort(vec.begin(), vec.end()); // 오름차순으로 정렬

		int result = 0, cnt = 0; // 출력할 결과, 현재 A가 잡아먹을수있는 B의 개수
		for (pair<int, int> i : vec)
		{
			if (i.group) cnt++; // 그룹이 1 즉 B면 cnt를 증가
			else result += cnt; // 그룹이 0 즉 A면 cnt -> 잡아먹을수있는 쌍의 수를 가산
		}

		cout << result << '\n';
	}
}
// 시간이 30배는 단축된거같다...