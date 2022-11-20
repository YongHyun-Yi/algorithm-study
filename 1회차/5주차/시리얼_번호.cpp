// 백준 1431번 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> str;
bool cmp(string a, string b);

// void merge(int start, int end)
// {
// 	vector<string> temp(n);
// 	int mid = (start + end) / 2;
// 	int start_index = start;
// 	int mid_index = mid;

// 	for (int i = start; i < end; i++)
// 	{
// 		if (start_index == mid) temp[i] = str[mid_index++];
// 		else if (mid_index == end) temp[i] = str[start_index++];
// 		else if (cmp(str[start_index], str[mid_index])) temp[i] = str[start_index++];
// 		else temp[i] = str[mid_index++];
// 	}

// 	for (int i = start; i < end; i++) str[i] = temp[i];
// }

// void merge_sort(int start, int end)
// {
// 	if (end == start + 1) return;

// 	int mid = (start + end) / 2;
// 	merge_sort(start, mid);
// 	merge_sort(mid, end);
// 	merge(start, end);
// }

bool cmp(string a, string b)
{
	if (a.length() < b.length()) return true;

	else if (a.length() == b.length())
	{
		int a_num = 0, b_num = 0;
		for (int x : a) if (x >= '0' && x <= '9') a_num += x - '0';
		for (int x : b) if (x >= '0' && x <= '9') b_num += x - '0';

		if (a_num < b_num) return true;

		else if (a_num == b_num)
		{
			int index = 0;
			while(a[index] == b[index]) index++;
			if (a[index] < b[index]) return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		str.push_back(a);
	}

	sort(str.begin(), str.end(), cmp);
	// merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << str[i] << '\n';
}

// 글자 길이 -> 문자열은 마지막에 null 문자가 들어가서 문자열의 끝을 알림
// strcmp랑 비슷한 방식으로 생각함
// 숫자는 변수를 따로 만들어서 '0' ~ '9'를 - '0' 한걸 더함

// 우선순위
// 1. null 문자
// 2. 숫자 총합
// 3. 사전순 (숫자가 같은경우 숫자가 먼저온다)
// 숫자가 먼저 오는건 기존의 sort를 사용하면 될듯
// 아니면 아스키 숫자로 비교

// merge sort말고 sort의 비교함수로 만들어도 될것같음