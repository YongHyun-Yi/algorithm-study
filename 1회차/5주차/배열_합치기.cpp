// 백준 11728번 문제

#include <iostream>

using namespace std;

int arr_a[1000000];
int arr_b[1000000];
int temp[2000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr_a[i];
	for (int i = 0; i < m; i++) cin >> arr_b[i];

	int index_a = 0, index_b = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (index_a == n) temp[i] = arr_b[index_b++]; // 인덱스가 사이즈를 넘어섰는지 체크가 우선
		else if (index_b == m) temp[i] = arr_a[index_a++];
		else if (arr_a[index_a] <= arr_b[index_b]) temp[i] = arr_a[index_a++]; // 그 다음 값을 비교
		else temp[i] = arr_b[index_b++];

		// if (index_a < n && index_b < m) << 이 부분과 밑의 index_a < n 부분은 중복이 된다
		// {
		// 	if (arr_a[index_a] <= arr_b[index_b])
		// 		temp[i] = arr_a[index_a++];
		// 	else
		// 		temp[i] = arr_b[index_b++];
		// }
		// else if (index_a < n)
		// 	temp[i] = arr_a[index_a++];
		// else
		// 	temp[i] = arr_b[index_b++];
	}
	for (int i = 0; i < n + m; i++)
		cout << temp[i] << ' ';
}