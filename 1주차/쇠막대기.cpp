// 백준 10799번 문제

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> st;
	string str;
	int count = 0;
	char prev;

	cin >> str;
	for (char c : str)
	{
		if (st.empty() || c == '(')
		{
			st.push(c);
		}
		else // c == ')'
		{
			if (prev == '(')
			{
				st.pop();
				count += st.size();
			}
			else if (prev == ')')
			{
				st.pop();
				count++;
			}
		}
		prev = c;
	}
	cout << count;
}

// 괄호짝이 맞으면 pop 아니면 push
// 레이저 발사되면 현재 stack의 사이즈만큼 자른갯수 + 1
// 그냥 괄호 하나가 끝나면 자른개수 + 1 ex) 1번 쏜 1 토막은 2 개로 나뉨, 자른횟수 + 마지막에 1개추가
// 똑같이 짝을 만나서 pop이 될때 얘가 레이저인지 막대기인지 구별해야함