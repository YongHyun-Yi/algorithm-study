// ���� 2493�� ����

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, select_top;
	stack<pair<int, int>> tops;
	tops.push({100000001, 0}); // ù��°�� ���� �ι�°�� �ε���

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> select_top;
		while (tops.top().first < select_top)
			tops.pop();
		cout << tops.top().second << " "; // �ε��� �� ���° ž���� ���
		tops.push({select_top, i});
	}
}

// ���� Ÿ���� ������ ���δ� pop���� ���ŵǰ� 0��°�� ���ü��ۿ� ����
// ���������� ž�� �ϳ� �� �����
// fair �ڷ����� ���� ž�� ���̻Ӹ� �ƴ϶� �ε����� �����ؼ� push
// ���� stack������ �����Ϸ����ؼ� �ε������� Ȯ���Ϸ���
// ������ ������ ������ �����鼭 Ȯ���߱⿡ ���������
// O(N^2)�� �ð��� �ʿ�
// ���� ����� ����Ѵٸ� �׻� ����ž�� top�� ���ԵǴ� �ٷ� �񱳰���

// -----------------------------------------------------------

// int main()
// {
// 	int n, nb;
// 	stack<int> tops, answer;

// 	cin >> n;
// 	while (n)
// 	{
// 		cin >> nb;
// 		tops.push(nb);
// 		n--;
// 	}

// 	int select_top;
// 	while (tops.size() > 1)
// 	{
// 		select_top = tops.top();
// 		tops.pop();
// 		stack<int> check_tops = tops;

// 		while (true)
// 		{
// 			if (check_tops.size() == 0)
// 			{
// 				answer.push(check_tops.size());
// 				break;
// 			}
// 			if (check_tops.top() > select_top)
// 			{
// 				answer.push(check_tops.size());
// 				break;
// 			}
// 			else
// 				check_tops.pop();
// 		}
// 	}
// 	answer.push(0);

// 	while (answer.size())
// 	{
// 		cout << answer.top() << " ";
// 		answer.pop();
// 	}

	// ���ú����� ������ ����� ����
	// ���û���� 1���� Ŭ������ while�ݺ� - �ι��� ž������ ����Ǽ� üũ, ù��° ž�� ������ 0�� ����
		// �켱 ������ ���� ���������� ������ �ְ� pop, ������--
		// ���û���� 0���� Ŭ������ while�ݺ� - ������ Ž��
			// ���ú����� ������ ����� ī��
			// top�� �������� ū ���� ��Ÿ�������� pop, ������--
			// ��Ÿ���� ��ȿ� ���ÿ� ������� push, ����� �� n��°�� �ȴ�
			// ������ 0���� ���ϸ� ����� push -> 0�� ��, �� ���Ǻб⸦ ��� ó������
	// ��ȿ� 0 push
	// �ܾ� ����� 0���� Ŭ������ while�ݺ�, top�� �ϳ��� ����ϰ� pop
	// ������ �¾����� �ð��ʰ��� ������...
// }
