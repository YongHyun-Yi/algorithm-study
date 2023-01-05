// 백준 7785번 문제

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	unordered_set<string> workers;

	int n;
	cin >> n;
	while (n--)
	{
		string name, state;
		cin >> name >> state;

		if (state == "enter") workers.insert(name);
		else workers.erase(name);
	}

	vector<string> result(workers.begin(), workers.end());
	sort(result.begin(), result.end(), greater<string>());

	for (auto lest : result) cout << lest << '\n';
}

// unordered set을 정렬하려고 하면 컴파일 오류가 발생한다
// 그래서 정답코드에서는 vector로 옮기고 정렬하는것같다
// 파이썬에서 봤던 set이라는 자료구조도 있는듯....중복을 허용하지 않고 자동정렬된다고함
//
// sort의 세번째 인자에 정렬방향 + 자료형 을 사용할수있나...?