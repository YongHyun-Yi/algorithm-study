// 백준 1541번 문제

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sign = 1, result = 0, nb = 0;
	string str;
	cin >> str;
	
	for (char c : str)
	{
		if (c >= '0' && c <= '9')
		{
			nb *= 10;
			nb += c - '0';
		}
		else if (c == '+' || c == '-')
		{
			result += nb * sign;
			nb = 0;
			if (sign && c == '-') sign = -1;
		}
	}
	result += nb * sign;
	cout << result;
}
// 10 + 30 - 20 + 50 - 10 = 60
// 10 + 30 - (20 + 50) - 10 = -40
// -가 연속해서 나오면 그대로 음수끼리 합치고
// +가 나오면 -에서 +까지 더한후 -1을 곱함
// 그냥 -가 한번 나오면 +가 두번나올때까지 뺄셈
// (-+)+ 이렇게 두번째 +부터 부호가 바뀌도록 하면...?
//
// 정답코드보고 배운것
// 그냥 -가 나온뒤로는 모두 -로 처리해버리면 됨