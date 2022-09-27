// 백준 1874번 문제

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n, mx, nb, input = 1, no = 0;
	string cmds;
	stack<int> st;

	cin >> n;
	mx = n;
	while(n)
	{
		cin >> nb;
		if (input <= nb)
			{
				while (input <= nb)
				{
					st.push(input);
					cmds.push_back('+');
					input++;
				}
			}
		if (st.top() != nb)
		{
				no = 1;
				break;
		}
		else
		{
			cmds.push_back('-');
			st.pop();
		}
		
		n--;
	}
	if (no)
		cout << "NO";
	else
		for (char c : cmds)
			cout << c << '\n';
	
	// 최근입력값 push할때마다 ++연산자 적용
	// nb와 top이 일치하지 않으면
	// nb가 input보다 더 크면 push
	// 입력받은 nb랑 일치하면 -
	// 최대까지 +했는데도 nb랑 일치하지 않으면 NO
}