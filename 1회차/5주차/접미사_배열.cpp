// 백준 11656번 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ls;
vector<string> temp;

void merge(int start, int end)
{
	temp.clear();
	int mid = (start + end) / 2;
	int start_index = start;
	int mid_index = mid;

	for (int i = start; i < end; i++)
	{
		if (start_index == mid) temp.push_back(ls[mid_index++]);
		else if (mid_index == end) temp.push_back(ls[start_index++]);
		else
		{
			int cmp_index = 0; // 문장의 길이가 겹치는 경우가 없으니 둘이 null이 아닐떄를 조건으로 넣을 필요가 없음
			while (ls[start_index][cmp_index] == ls[mid_index][cmp_index]) cmp_index++;

			if (ls[start_index][cmp_index] < ls[mid_index][cmp_index]) temp.push_back(ls[start_index++]);
			else temp.push_back(ls[mid_index++]);
		}
	}

	for (int i = start; i < end; i++) ls[i] = temp[i - start];
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
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) ls.push_back(str.substr(i));

	merge_sort(0, ls.size());

	for (int i = 0; i < ls.size(); i++) cout << ls[i] << '\n';
}

// 길이 상관없음
// 이번엔 진짜로 strcmp