// ���� 10799�� ����

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

// ��ȣ¦�� ������ pop �ƴϸ� push
// ������ �߻�Ǹ� ���� stack�� �����ŭ �ڸ����� + 1
// �׳� ��ȣ �ϳ��� ������ �ڸ����� + 1 ex) 1�� �� 1 �丷�� 2 ���� ����, �ڸ�Ƚ�� + �������� 1���߰�
// �Ȱ��� ¦�� ������ pop�� �ɶ� �갡 ���������� ��������� �����ؾ���