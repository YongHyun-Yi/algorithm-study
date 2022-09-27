// 백준 2493번 문제

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
	tops.push({100000001, 0}); // 첫번째가 높이 두번째가 인덱스

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> select_top;
		while (tops.top().first < select_top)
			tops.pop();
		cout << tops.top().second << " "; // 인덱스 즉 몇번째 탑인지 출력
		tops.push({select_top, i});
	}
}

// 높은 타워가 없으면 전부다 pop으로 제거되고 0번째가 나올수밖에 없음
// 인위적으로 탑을 하나 더 세운셈
// fair 자료형을 통해 탑의 높이뿐만 아니라 인덱스도 보존해서 push
// 나는 stack만으로 구현하려고해서 인덱스값을 확인하려면
// 스택을 복사후 일일이 뺴가면서 확인했기에 결과적으로
// O(N^2)의 시간이 필요
// 위의 방법을 사용한다면 항상 높은탑만 top에 남게되니 바로 비교가능

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

	// 스택변수와 스택의 사이즈를 가짐
	// 스택사이즈가 1보다 클때까지 while반복 - 두번쨰 탑까지만 경우의수 체크, 첫번째 탑은 무조건 0이 나옴
		// 우선 스택의 가장 마지막수를 변수에 넣고 pop, 사이즈--
		// 스택사이즈가 0보다 클때까지 while반복 - 끝까지 탐색
			// 스택변수와 스택의 사이즈를 카피
			// top이 변수보다 큰 수가 나타날때까지 pop, 사이즈--
			// 나타나면 답안용 스택에 사이즈값을 push, 사이즈가 곧 n번째가 된다
			// 사이즈 0까지 못하면 사이즈를 push -> 0이 들어감, 이 조건분기를 어떻게 처리할지
	// 답안에 0 push
	// 단안 사이즈가 0보다 클때까지 while반복, top을 하나씩 출력하고 pop
	// 로직은 맞았으나 시간초과가 나버림...
// }
