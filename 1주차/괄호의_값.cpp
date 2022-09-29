// ���� 2504�� ����

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


// ������ �����Ӱ� �����ؾ��ϴ� �ɷ��� �䱸�Ǵ� ����
// ������ �հ���� �����ϴ°� �ƴ϶� �հ���� ���������ϰ�
// ������ ���� ��ȣ��ŭ �����ִ� ���...
// ���� ���ʿ� �ִ� ��ȣ�� ���� ����Ѵ�
// ������ �Է��� ���� ������ ���� �����ʿ���� ���ڿ��� ���ÿ��� ���ε��� �˻��Ѵ�
// �̸� ���ؼ� ��Ҹ� �޴� for���� �ƴ϶� �ε����� �޴� for���� ���
// ---------------------------------------------------------
// �踷���ó�� ������ �Է¹��� ���ڿ��� ������ ������ �����
// ������ ���ڿ��� ([ ��� �״�� ������� )] ��� �����?
// ������ �հ���� ��� �����ϴ°�...?