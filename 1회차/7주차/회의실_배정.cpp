// 백준 1931번 문제

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second) return true; // 빨리 끝나는가
	else if ((a.second == b.second) && (a.first < b.first)) return true; // 같이 끝나면 빨리 시작하는가?
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, cmp); // 끝나는 시간순으로 정렬...?

	int cnt = 0, last_time = 0;
	for (int i = 0; i < n; i++)
	{
		if (last_time > arr[i].first) continue; // 이전 회의가 진행중이니 현재 선택한 회의는 진행불가
		cnt++;
		last_time = arr[i].second;
	}

	cout << cnt;
}

// 먼저 끝나는 순으로 시간을 정렬한다는 귀류법이 핵심인듯...
// 귀류법을 아직 이해못하겠음...
// 일찍 끝난다는건 모르겠고 회의진행시간이 짧아야 한다고 생각은했는데
// 얼추 비슷한 말인것같기도하고...
// 일단 먼저 시작한다고해서 선택해야되는건 무조건 아님