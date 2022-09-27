// 백준 10773번 문제

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int k, nb, result = 0;
	stack<int> jb;

	cin >> k;
	while(k)
	{
		cin >> nb;
		if (nb == 0)
			jb.pop();
		else
			jb.push(nb);
		k--;
	}
	while(jb.size())
	{
		result += jb.top();
		jb.pop();
	}
	cout << result;
}