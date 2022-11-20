#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define age first
#define name second

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	return a.age < b.age; // 같은 경우는 제외해야 에러가 뜨지않는다, stable sort는 우선수위가 같은 요소는 처음 순서를 유지한채로 정렬한다
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, _age;
	string _name;

	vector<pair<int, string>> vec;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> _age >> _name;
		vec.push_back({_age, _name});
	}
	
	stable_sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << vec[i].age << ' ' << vec[i].name << '\n';
}