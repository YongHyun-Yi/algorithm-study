// 백준 9012번 문제

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		stack<char> st;
		string str;
		int is_valid = 1;
		cin >> str;
		for (char c : str)
		{
			if (c == '(')
				st.push(c);
			else if (c == ')')
				if (st.empty())
				{
					is_valid = 0;
					break;
				}
				else
					st.pop();
		}
		if (is_valid && st.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}