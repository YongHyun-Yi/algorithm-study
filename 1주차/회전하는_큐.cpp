// ���� 1021�� ����

#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, count = 0;;
	deque<int> que;

	cin >> n;
	for (int i = 1; i <= n; i++) que.push_back(i);

	cin >> m;
	while(m--)
	{
		int target, target_i;
		cin >> target;
		target_i = find(que.begin(), que.end(), target) - que.begin();
		while (target != que.front())
		{
			if (target_i > que.size() - target_i) // �տ��� �������� ��ġ, �ڿ��� �������� ��ġ
			{
				que.push_front(que.back());
				que.pop_back();
			}
			else
			{
				que.push_back(que.front());
				que.pop_front();
			}
			count++;
		}
		que.pop_front();
	}
	cout << count;

	return 0;
}

// algorithm�� find �Լ��� Ÿ���� �ε����� �˾Ƴ����ִ�....
	// deque������� ������ deque�� ����ϸ� �ȵȴٴ°��� �����Ұ�

	// -----------------------------------------------------

	// �̾Ƴ��°� ù���� ���Ҹ� ������
	// �׷��⿡ �ش� �ε����� �ƴϸ� ��� ȸ�����Ѿ���
	// �ε������� ���ϰ� ���Ҹ� �̾Ƴ���
	// �����̵� �������̵� 'ȸ���� �� ����ؾ��ϴ°�'�� ���