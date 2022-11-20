// 백준 3015번 문제

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
	stack<pair<int, int>> people;
	int n;
	long long result = 0;

	cin >> n;
	while(n--)
	{
		int height, count = 1;
		cin >> height;
		while (!people.empty() && people.top().first <= height)
		{
			result += people.top().second;
			if (people.top().first == height)
				count += people.top().second;
			people.pop();
		}
		if (!people.empty())
			result++;
		people.push({height, count});
	}
	cout << result;
}

// 중복되는 값이 나오면 pop 하고나서 push하기전에
// 증가된 count값과 함께 pair형으로 대입됨
// 중복된 값이 입력될때는 매번 누적되서 결과에 더해지지만
// 나중에 큰값이 들어오면 누적된값 한번만 들어가고 끝
// 매번 count 변수를 초기화 하는대신 pair형으로 보존함
// 중복된 값이 아닐경우 그냥 push하면 증가연산자를 써도되지만
// 중복된 값도 함께 포괄해서 사용하기위해 count를 더하는식으로
// --------------------------------------
// int main()
// {
// 	int n, same = 1;
// 	long long result = 0;
// 	stack<int> people;

// 	cin >> n;
// 	while(n--)
// 	{
// 		int height;
// 		cin >> height;

// 		if (!people.empty() && people.top() > height)
// 			same = 1;

// 		while (!people.empty())
// 		{
// 			result += same;
// 			cout << "current result is : " << result << '\n';
// 			if (people.top() < height)
// 			{
// 				people.pop();
// 				same = 1;
// 			}
// 			else
// 			{
// 				if (people.top() == height)
// 					same++;
// 				else if (people.top() > height)
// 					same = 1;
// 				break;
// 			}
// 		}
// 		if (!people.empty())
// 		{
// 			result++;
// 			cout << "lest plus result is : " << result << '\n';
// 		}
// 		people.push(height);
// 	}
// 	cout << result;
// }

// 이전 문제들과 비슷함
// 대신 같은값까지 포함
// empty상태에서 push만 아니면 push와 pop 모두 result값이 증가
// 같은 값의 처리에서 문제가 발생함...
// 같은 값이 2개면 그냥 같은값일때 똑같이 result++을 해줘도 되지만
// 3개 이상이되면 같은 값끼리도 쌍이되는 경우의 수가 (n - 1)만큼 늘어남
// 그리고 같은값끼리 서로를 보는 수말고도 맨 마지막수가 같은값들을 보는 수도 있음
// 같은 값이 2개이하일때와 3개이상일때를 주의할것
// 일반 값일때와 같은 값일때 모두 똑같은 변수로 넣어주도 같은 값이 연속해서 나올때
// 해당 변수를 조작해주는식 혹은 계속 증가시키되 같지않은 값이 나오면 초기화