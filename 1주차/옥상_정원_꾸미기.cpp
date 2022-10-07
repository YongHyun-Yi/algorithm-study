// 백준 6198번 문제

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

// 같은 현상을 방향만 바꿔서 생각한다
// 내가 볼 수 있는 수라는건 반대로 내가 보일 수 있는 수
// 즉 나를 볼 수 있는 수를 구하는것과도 같다
// 물론 중간과정을 보면 관리인이 확인할수있는 옥상의 수와 비교해서
// 달라 질 수 있겠지만
// 우리가 원하는 결과값과는 차이가 없어진다
// 나를 볼 수 있는 건물만 스택에 남겨놓고 사이즈값으로 변수에 가산
// 사이즈값은 곧 '나를 볼 수 있는 건물만 남아있는 값'으로 의미부여가 가능
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

// 탑 문제와 비슷해보임
// pair를 이용해서 저장
// 입력값이 top보다 크면 pop
// 입력값의 인덱스 - top의 인덱스 - 1 (-1을 해줘야 바로 큰 빌딩이 나올때 0이 나옴)
// 입력값이 top보다 클때까지 반복문 돌려서 뺴줘야함
// 그래야 이전의 큰 빌딩들의 값도 뱉어줄수있음
// 반복문이 끝나고 마지막에 큰 빌딩과 작은빌딩 여러개가 남았을때
// 스택의 사이즈로 값을 구할수있음
// 
// 반복문을 한번돌고 남은 인자들을 처리할때 예외가 많음