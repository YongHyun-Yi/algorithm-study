// 백준 9375번 문제

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string name, type;
	int t, n;

	cin >> t;
	while (t--)
	{
		unordered_map<string, string> items;
		unordered_set<string> types;

		cin >> n;
		while (n--)
		{
			cin >> name >> type;
			items[name] = type;
			types.insert(type);
		}

		int day = 0;
	}
}

/*

	a
	b
	c
	세 종류가 있다고 치면

		처음 들어올때 + / 나머지랑 조합할때 +
	a 		1					0
	b 		1 					1
	c 		1 					2

	2^0 ~ 2^n-1 까지 모두 더한것

	만약 중복되는 종류가 있다고 치면
	이후에들어오는것이 이전의 것을 덮어쓴다는 가정하에

		처음 들어올때 + / 나머지랑 조합할때 +
	a 		1					0
	b 		1 					1
	a 		1 					1

	-> 틀렸음

	<반례>

	1
	6
	a g
	b g
	c g
	d h
	e h
	f i

	정답: 23

*/