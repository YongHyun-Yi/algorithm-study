// 백준 2295번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
	vector<int> input, u;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < n; i++)
		if (i == 0 || input[i] != input[i - 1])
			u.push_back(input[i]);
				// 중복 제거
	
	// 조합으로 3개를 뽑아낸다 (정렬기준 끝에서 3개 조합은 뽑아내면 안됨 -> 더해서 걔네보다 클 수 있는 경우가 없음)
	// 조합으로 뽑아서 나온수를 더함, 더한 수가 해당 벡터 내에 있는지 이분탐색
	// 오름차순으로 최대값을 갱신해가면서 탐색? -> 벡터 크기에 비례해서 시간이 길어짐...
}