// ���� 4949�� ����

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
				if ( brk.empty() || brk.top() != '(') // ���ǹ��� ������ �����Ѵ�, ����ִ� �迭�� �����ؼ� segfault�� ��������
				{
					error = 1;
					break;
				}
				brk.pop(); // if���� �ɸ��� ������ break�� Ż���ϴ� else�� ���� �ʾƵ� ����....
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
		if (error || !brk.empty()) // ������ no�� ����ϰ� Ż���ϸ� ���⼭ �ߺ� ����� �Ǳ⶧���� �÷��� ������ ����ؼ� �ϰ�����Ѵ�
			cout << "no\n";
		else
			cout << "yes\n";
	}
}