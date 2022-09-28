// ���� 3986�� ����

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n, count = 0;
	cin >> n;
	while(n--)
	{
		stack<char> st;
		string str;

		cin >> str;
		for (char c : str)
		{
			if (!st.empty() && st.top() == c) st.pop();
			else st.push(c);
		}
		if (st.empty()) count++;
	}
	cout << count;
}

// ������ ��������� ������ �߸� ������
// ------------------------