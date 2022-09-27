// ���� 1874�� ����

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
	
	// �ֱ��Է°� push�Ҷ����� ++������ ����
	// nb�� top�� ��ġ���� ������
	// nb�� input���� �� ũ�� push
	// �Է¹��� nb�� ��ġ�ϸ� -
	// �ִ���� +�ߴµ��� nb�� ��ġ���� ������ NO
}