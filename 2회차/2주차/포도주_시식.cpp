// 백준 2156번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int input[10001];
int drink[10001];
int mx;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> input[i];
	
	drink[1] = input[1];
	drink[2] = input[1] + input[2];

	for (int i = 3; i <= n; i++) // 1부터 채우면 -3을해도 0으로 초기화한 0번 인덱스를 본다, segefault를 피할수있고 초기값을 적게 넣어줘도된다
		drink[i] = max({drink[i - 1], drink[i - 2] + input[i], drink[i - 3] + input[i] + input[i - 1]}); // 마시지 않았거나, 이번에 마시고 바로 직전은 마시지 않았거나, 이번이랑 직전에 연달아 마시고 전전에는 마시지 않았거나

	cout << drink[n];
}