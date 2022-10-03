// 백준 1021번 문제

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
			if (target_i > que.size() - target_i) // 앞에서 세었을때 위치, 뒤에서 세었을때 위치
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

// algorithm의 find 함수로 타겟의 인덱스를 알아낼수있다....
	// deque문제라고 무조건 deque만 사용하면 안된다는것을 생각할것

	// -----------------------------------------------------

	// 뽑아내는건 첫번쨰 원소만 가능함
	// 그렇기에 해당 인덱스가 아니면 계속 회전시켜야함
	// 인덱스값을 비교하고 원소를 뽑아내고
	// 왼쪽이든 오른쪽이든 '회전을 총 몇번해야하는가'를 출력