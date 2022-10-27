// 백준 2910번 문제

#include <iostream>
#include <vector>

#define nb first
#define cnt second

using namespace std;

vector<pair<long long, long long>> arr;
vector<pair<long long, long long>> temp;

void merge(int start, int end)
{
	temp.clear();
	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;

	for(int i = start; i < end; i++)
	{
		if (start_index == mid) temp.push_back(arr[mid_index++]);
		else if (mid_index == end) temp.push_back(arr[start_index++]);
		else if (arr[start_index].cnt >= arr[mid_index].cnt) temp.push_back(arr[start_index++]);
		else temp.push_back(arr[mid_index++]);
	}

	for(int i = start; i < end; i++) arr[i] = temp[i - start];
		// arr의 인덱스에 맞추기위해서 temp도 i = start에서 시작하지만 temp는 clear를 하고
		// push back으로 0인덱스부터 새로 집어넣은거라 i - start를 해줬음
		// - start를 빼도 정상적으로 돌아가긴 하는데 vscode가 보정해주는거일수도...?
}

void merge_sort(int start, int end)
{
	if (end == start + 1) return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;

		bool check = false;
		for (int j = 0; j < arr.size(); j++)
		{
			if (a == arr[j].nb)
			{
				arr[j].cnt++;
				check = true;
				break;
			}
		}
		if (!check) arr.push_back({a, 1}); // nb, cnt
	}

	merge_sort(0, arr.size()); // merge_sort 대신 merge로 작성하는 오타...뭐 이런 실수를;

	for (pair<long long, long long> x : arr)
	{
		while (x.cnt--) cout << x.nb <<' ';
	}
}

// 1. 빈도가 높은게 먼저
// 2. 빈도가 같으면 먼저 입력된게 먼저
// counting?
// 정렬후 인접하다는 속성을 이용
// 정렬하면 먼저 입력된게 뭔지 모름
// 정렬하기전에 중복된 요소가 제거된 순서목록을 만들필요가 있음?
// pair를 사용하면 입력받을때 중복된값은 새로 넣지말고 second 값을 늘려주면...
// 입력받을때마다 vector 전체를 탐색?