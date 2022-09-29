// 백준 2504번 문제

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int result = 0, add_num = 1, error = 0;
	stack<char> st;
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			add_num *= 2;
			st.push(str[i]);
		}
		else if (str[i] == '[')
		{
			add_num *= 3;
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				error = 1;
				break;
			}
			st.pop();
			if (str[i - 1] == '(')
				result += add_num;
			add_num /= 2;
		}
		else if (str[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				error = 1;
				break;
			}
			st.pop();
			if (str[i - 1] == '[')
				result += add_num;
			add_num /= 3;
		}
	}
	if (st.empty() && !error)
		cout << result;
	else
		cout << 0;
}


// 수식을 자유롭게 구성해야하는 능력이 요구되는 문제
// 곱계산과 합계산을 구별하는게 아니라 합계산을 공통으로하고
// 합해질 수에 괄호만큼 곱해주는 방식...
// 가장 안쪽에 있는 괄호가 합을 담당한다
// 직전의 입력을 받을 변수를 따로 만들필요없이 문자열과 스택에서 따로따로 검사한다
// 이를 위해서 요소를 받는 for문이 아니라 인덱스를 받는 for문을 사용
// ---------------------------------------------------------
// 쇠막대기처럼 직전에 입력받은 문자열을 저장할 변수를 만든다
// 직전의 문자열이 ([ 라면 그대로 점수계산 )] 라면 곱계산?
// 곱계산과 합계산을 어떻게 구별하는가...?