// 백준 15649번 문제

#include <iostream>

using namespace std;

int n, m; // 전역으로 빼면 함수 인자를 줄일 수 있음
int print_array[9], is_used[9];

void rec(int x)
{
	if (x == m) // 현재 인덱스가 출력해야되는 갯수와 같으면 (주의 : 인덱스는 0부터 센다)
	{
		for (int i = 0; i < m; i++)
			cout << print_array[i] << ' ';
		cout << '\n';
		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!is_used[i])
		{
			is_used[i] = 1;
			print_array[x] = i;
			rec(x + 1);
			is_used[i] = 0; // 일방통행이니까 중복해서 나올 걱정이 없음
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rec(0); // 배열의 0번째부터 시작
}