// 백준 1158번 문제

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	list<int> ls;
	for (int i = 0; i < n; i++)
		ls.push_back(i + 1);
	
	cout << "<";
	auto selector = ls.begin();
	while (ls.size() > 1)
	{
		for (int count = 1; count < k; count++)
		{
			selector++;
			if (selector == ls.end())
			{
				selector = ls.begin();
			}
		}
		
		cout << *selector << ", ";
		selector = ls.erase(selector);

		if (selector == ls.end())
			{
				selector = ls.begin();
			}
	}
	cout << *ls.begin() << ">";

	return 0;
}