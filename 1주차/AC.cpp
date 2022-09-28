// ���� 5430�� ����

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		string cmd, input_arr;
		int size, temp = 0, error = 0, rev = 0;
		cin >> cmd >> size >> input_arr;

		deque<int> que;
		for (int i = 1; i + 1 < input_arr.size(); i++)
		{
			if (input_arr[i] == ',')
			{
				que.push_back(temp);
				temp = 0;
			}
			else temp = temp * 10 + (input_arr[i] - '0');
		}
		if (temp != 0) que.push_back(temp); // ����� 0 �ϋ��� ����ó���� ���������� ������ ����ó���� ���� �������� �𸣰���...

		for (char c : cmd)
		{
			if (c == 'R') rev = 1 - rev; // �̷������� ����Ҽ��ִ�

			else if (c == 'D')
			{
				if (que.empty())
				{
					error = 1;
					break;
				}
				else
				{
					if (rev) que.pop_back();
					else que.pop_front();
					size--;
				}
			}
		}
		if (error) cout << "error\n";
		else
		{
			if (rev) reverse(que.begin(), que.end());

			cout << '[';
			while (size--)
			{
				cout << que.front();
				if (size > 0)
					cout << ',';
				que.pop_front();
			}
			cout << "]\n";
		}
	}
}

// �Ź� �迭�� �����ؼ� �����°� �ƴ϶�
// ������ ����� int������ ���ó�� �޾Ƽ�
// �տ��� ���� �ڿ��� ������ ����
// ���߿� ����ϱ������� �������� ���� �����ϰ�
// �ѹ��� ��������ν� �ð��ʰ��� ���Ҽ�����
// --------------------------