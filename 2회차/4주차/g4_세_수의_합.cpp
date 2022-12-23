// 백준 2295번 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> u, comb_two;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		u.push_back(input);
	}

	sort(u.begin(), u.end());
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			comb_two.push_back(u[i] + u[j]);
				// 두개끼리 더한 배열
	
	sort(comb_two.begin(), comb_two.end());
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (binary_search(comb_two.begin(), comb_two.end(), u[i] - u[j]))
			{
				cout << u[i];
				return(0);
			}
		}
	}

	// 조합으로 3개를 뽑아낸다 (정렬기준 끝에서 3개 조합은 뽑아내면 안됨 -> 더해서 걔네보다 클 수 있는 경우가 없음)
	// 조합으로 뽑아서 나온수를 더함, 더한 수가 해당 벡터 내에 있는지 이분탐색
	// 오름차순으로 최대값을 갱신해가면서 탐색? -> 벡터 크기에 비례해서 시간이 길어짐...
	//
	// 영상보고 알게된 풀이
	// 우선 2중반복문으로 2개끼리 더한 배열을 만든다
	// 거기서 또 반복문 하나를 돌리면서 2 + 1개를 더한 값이 합이되는 배열을 만든다
	// 합이되는 배열에서 반복문 하나를 다시 돌리면서 3 - 1개가 2중반복문으로 만든 배열에 있는지 이분탐색한다
	// 근데 어차피 2 + 1개 합의 배열은 따로 만들필요 없이 기존 배열을 갖다쓰면 될거같음
	// 어차피 기존 배열에서 3개의 요소의 합이 같은 배열안에 있는 경우를 찾는거니까...
}