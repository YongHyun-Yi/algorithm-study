// 백준 1439번 문제

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;

	int num0_cnt = 0, num1_cnt = 0;
	char current_num = 0;
	for (char c : str)
	{
		if (c != current_num)
		{
			if (c == '0')
				num0_cnt++;
			else
				num1_cnt++;
			current_num = c;
		}
	}
	cout << min(num0_cnt, num1_cnt);
}