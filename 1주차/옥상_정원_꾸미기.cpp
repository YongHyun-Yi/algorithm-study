// ���� 6198�� ����

#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<int> bds;
	int n;
	long long result = 0;

	cin >> n;
	while(n--)
	{
		int input_height;
		cin >> input_height;
		while (!bds.empty() && bds.top() <= input_height)
			bds.pop();
		result += bds.size();
		bds.push(input_height);
	}
	cout << result;
}

// ���� ������ ���⸸ �ٲ㼭 �����Ѵ�
// ���� �� �� �ִ� ����°� �ݴ�� ���� ���� �� �ִ� ��
// �� ���� �� �� �ִ� ���� ���ϴ°Ͱ��� ����
// ���� �߰������� ���� �������� Ȯ���Ҽ��ִ� ������ ���� ���ؼ�
// �޶� �� �� �ְ�����
// �츮�� ���ϴ� ��������� ���̰� ��������
// ���� �� �� �ִ� �ǹ��� ���ÿ� ���ܳ��� ��������� ������ ����
// ������� �� '���� �� �� �ִ� �ǹ��� �����ִ� ��'���� �ǹ̺ο��� ����
// ------------------------------------------------------
// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	stack<pair<long long, int>> buildings;
// 	int n;
// 	long long result = 0;

// 	cin >> n;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		long long input_bd;
// 		cin >> input_bd;
// 		while (!buildings.empty() && buildings.top().first <= input_bd)
// 		{
// 			result += i - buildings.top().second - 1;
// 			buildings.pop();
// 		}
// 		buildings.push({input_bd, i});
// 	}

// 	pair<long long, int> last = {1000000000, -1};
// 	while (buildings.size() > 1)
// 	{
// 		if (buildings.top().first < last.first)
// 			last = buildings.top();
// 		buildings.pop();
// 		if (buildings.top().first > last.first)
// 		{
// 			cout << "will add : " << last.second - buildings.top().second << '\n';
// 			result += last.second - buildings.top().second;
// 		}
// 	}
	
// 	cout << result;
// }

// ž ������ ����غ���
// pair�� �̿��ؼ� ����
// �Է°��� top���� ũ�� pop
// �Է°��� �ε��� - top�� �ε��� - 1 (-1�� ����� �ٷ� ū ������ ���ö� 0�� ����)
// �Է°��� top���� Ŭ������ �ݺ��� ������ �������
// �׷��� ������ ū �������� ���� ����ټ�����
// �ݺ����� ������ �������� ū ������ �������� �������� ��������
// ������ ������� ���� ���Ҽ�����
// 
// �ݺ����� �ѹ����� ���� ���ڵ��� ó���Ҷ� ���ܰ� ����