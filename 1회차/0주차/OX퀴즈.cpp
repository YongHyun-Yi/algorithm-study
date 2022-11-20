#include <iostream>
#include <string>
using namespace std;

// 백준 8958번 문제

int main()
{
	int t, score, result;
	string str;
	cin >> t;
	while (t)
	{
		cin >> str;
		score = 0;
		result = 0;
		for (char c : str)
		{
			if (c == 'O')
				score++;
			else
				score = 0;
			result += score;
		}
		cout << result << '\n';
		t--;
	}
	return 0;
}