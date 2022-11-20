// 백준 1182번 문제

#include <iostream>

using namespace std;

int n, s, cnt = 0, numbers[20];

void rec(int x, int result)
{
	if (x == n) // 끝까지 도달했으면 종료
	{
		if (result == s) cnt++; // result가 s와 같으면 cnt + 1
		return;
	}

	rec(x + 1, result); // 현재 인덱스의 수를 더하지 않은 경우
	rec(x + 1, result + numbers[x]); // 현재 인덱스의 수를 더한 경우
		// 해당 부분수열에 더할지 말지 두가지의 경우의 수를 가지고있음
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	rec(0, 0); // 인덱스, 계속 더해나갈 값
	if (s == 0) cnt--; // 공집합을 의식해서 하나를 빼줌 -> 크기가 양인 부분집합만 계산하니까
	cout << cnt;
}

// -------------------------------------------------

// int n, s, cnt = 0, numbers[20], is_used[20];

// void rec(int x, int result)
// {
// 	if (result == s)
// 	{
// 		cnt++;
// 		return;
// 	}

// 	for (int i = x; i < n; i++)
// 	{
// 		result += numbers[x]; // 우선 더하고

// 		if (!is_used[i] && result <= s) // 현재값이 s를 초과하지 않았을때 다음수를 더하러 들어감
// 		{
// 			is_used[i] = 1;
// 			rec(x + 1, result);
// 			is_used[i] = 0;
// 		}
// 	}
// }

// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> n >> s;
// 	for (int i = 0; i < n; i++)
// 		cin >> numbers[i];
	
// 	rec(0, 0); // 인덱스, 계속 더해나갈 값
// 	cout << cnt;
// }
	// 시간초과