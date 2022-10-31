#include <iostream>
#include <string>

#define age first
#define name second

using namespace std;

pair<int, string> arr[100000];
pair<int, string> temp[100000];

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;
		// temp 배열을 사용하여 값을 비교후 정렬하여 대입
		// 하나의 배열을 둘로 쪼개서 비교할것이기 때문에
		// 중심점을 기준으로 인덱스 역할의 변수가 두개 필요함

	for (int i = start; i < end; i++)
	{
		if (start_index == mid) temp[i] = arr[mid_index++];
		else if (mid_index == end) temp[i] = arr[start_index++];
			// 각각의 인덱스 변수가 끝에 도달하면 다른 인덱스 변수를
			// 사용하여 남은 빈자리를 채워넣음

		else if (arr[start_index].age <= arr[mid_index].age) temp[i] = arr[start_index++];
			// 나이가 오름차순이여야 하고 나이가 같은 경우에도
			// 입력순서를 유지해야하니 a <= b 라면 temp에 a의 요소를 대입해줌
		else temp[i] = arr[mid_index++];
			// 아닐경우 temp에 b의 요소를 대입
	}

	for (int i = start; i < end; i++) arr[i] = temp[i];
		// 정렬이 끝난 요소들을 원래의 arr에 덮어씌움
}

void merge_sort(int start, int end)
{
	if (end == start + 1) return;
		// base condition : 배열의 사이즈가 1일때

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
		// 분할하는 과정
	
	merge(start, end);
		// 분할이 모두 끝났으면 재귀를 벗어나면서 병합 정렬
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int _age;
		string _name;
		cin >> _age >> _name;
			// 값을 입력받음
		arr[i].age = _age;
		arr[i].name = _name;
			// 입력받은 값을 배열에 대입
	}

	merge_sort(0, n);
		// 0부터 n까지의 범위를 merge sort로 정렬
		// n은 포함되지 않음

	for (int i = 0; i < n; i++)
		cout << arr[i].age << ' ' << arr[i].name << '\n';
}