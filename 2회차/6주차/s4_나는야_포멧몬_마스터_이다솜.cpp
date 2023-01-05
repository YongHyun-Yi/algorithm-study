// 백준 1620번 문제

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> pokedex_no;
	unordered_map<string, int> pokedex_name;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string poke_name;
		cin >> poke_name;

		pokedex_no.push_back(poke_name);
		pokedex_name[poke_name] = i;
	}

	while (m--)
	{
		string qeustion;
		cin >> qeustion;

		if (isdigit(qeustion[0])) cout << pokedex_no[stoi(qeustion) - 1] << '\n';
		else cout << pokedex_name[qeustion] << '\n';
	}
}

// 입력으로 포켓몬 순서의 숫자도 들어오는줄 알았음, 자꾸만 문제를 대충 읽음;
// atoi처럼 stoi라는 함수가 있음, isdigit도 복습