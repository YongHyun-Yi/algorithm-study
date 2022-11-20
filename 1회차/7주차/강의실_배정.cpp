// 백준 11000번 문제

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[400000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, nb;
	cin >> n;
	for (int i = 0; i < n * 2; i++)
	{
		cin >> nb;
		arr[i++] = {nb, 1};
		cin >> nb;
		arr[i] = {nb, -1};
	}

	sort(arr, arr + (n * 2));

	int result = 0, current_class = 0, index = 0, current_time = arr[0].first;
	while (1)
	{
		while (index < n * 2 && current_time == arr[index].first) // 인덱스가 유효할때 && 현재 시작지점을 포함해서 강의실 개수를 셀때
		{
			current_class += arr[index].second;
			index++;
		}
		// 새 강의가 열리면 튕겨져 나온다 'current_time == arr[index].first'가 성립하지 않기때문
		// 곧바로 닫히면 성립한다
		result = max(result, current_class);
		if (index == n * 2) break;
		// 인덱스를 다 채워서 튕겨져 나왔으면 그대로 루프 종료
		// 여태 센 결과는 반영해야하기 떄문에 reuslt를 갱신하고나서 체크한다
		current_time = arr[index].first;
	}

	cout << result;
}

// 정답코드 보고 배운것
// 문을 열고 닫고를 샏각해본다면
// 현재 몇개의 문이 동시에 열려있는지
// 그리고 열린문이 최대의 개수가 몇개인지를 생각해보면 쉽다
// 시작시간과 종료시간을 pair로 묶는게 아니라 따로 넣는것
// 현재 시간의 상태를 pair로 함꼐 묶는다는것
//
// -------------------------
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) cin >> arr[i].start_time >> arr[i].end_time;
	
// 	sort (arr, arr + n);
// 	int last_time = 0, cnt = 1;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (last_time > arr[i].start_time)
// 		{
// 			cnt++;
// 			continue;
// 		}
// 		last_time = arr[i].end_time;
// 	}

// 	cout << cnt;
// }