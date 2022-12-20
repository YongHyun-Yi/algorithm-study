// 백준 10816번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> src;

int left_search(int tofind)
{
	int start_idx = 0;
	int end_idx = n;
		// 어차피 end_idx를 직접 참조하지 않으니
		// 리턴값에서 start_idx의 위치에 따라 +1 해줄필요없이
		// end_idx에 n을 대입해버리면 된다
		// 참조는 무조건 mid만 본다

	while (start_idx < end_idx)
	{
		int mid_idx = (start_idx + end_idx) / 2;

		if (src[mid_idx] >= tofind)
			end_idx = mid_idx;
		else
			start_idx = mid_idx + 1;
	}
		// tofind를 삽입할수 있는 위치를 찾음
		//
		// mid_index를 참조한 값이 tofind보다 작은경우
		// 해당 값을 뒤로 밀고 그 자리에 들어갈 수 없으므로
		// 탐색 시작점을 우측으로 이동시키는데 mid + 1을 대입
		//
		// 반대로 tofind보다 큰 경우
		// 해당 값을뒤로 밀고 그 자리에 들어갈 수 있으므로
		// 탐색 종료점을 좌측으로 이딩시키는데 mid를 대입

	return (start_idx);
}

int right_search(int tofind)
{
	int start_idx = 0;
	int end_idx = n;

	while (start_idx < end_idx)
	{
		int mid_idx = (start_idx + end_idx) / 2;

		if (src[mid_idx] > tofind)
			end_idx = mid_idx;
		else
			start_idx = mid_idx + 1;
	}

	return (start_idx);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		src.push_back(input);
	}

	sort(src.begin(), src.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tofind, left, right;
		cin >> tofind;

		left = left_search(tofind);
		right = right_search(tofind);
		
		cout << right - left << ' ';
	}
}