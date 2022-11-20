// 백준 4949번 문제

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	while (true)
	{
		getline(cin, str);
		if (str == ".") break;

		int error = 0;
		stack<char> brk;
		for (char c : str)
		{
			if (c == '(' || c == '[') brk.push(c);

			else if (c == ')')
			{
				if ( brk.empty() || brk.top() != '(') // 조건문의 순서에 유의한다, 비어있는 배열을 참조해서 segfault가 날수있음
				{
					error = 1;
					break;
				}
				brk.pop(); // if에서 걸리면 어차피 break로 탈출하니 else를 쓰지 않아도 됐음....
			}
			else if (c == ']')
			{
				if (brk.empty() || brk.top() != '[')
				{
					error = 1;
					break;
				}
				brk.pop();
			}
		}
		if (error || !brk.empty()) // 위에서 no를 출력하고 탈출하면 여기서 중복 출력이 되기때문에 플래그 변수를 사용해서 일괄출력한다
			cout << "no\n";
		else
			cout << "yes\n";
	}
}