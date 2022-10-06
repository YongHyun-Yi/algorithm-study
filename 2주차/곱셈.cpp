// 백준 1629번 문제

#include <iostream>

using namespace std;
using ll = long long; // using 찾아보기

ll rec_pow(ll nb, ll power, ll mod)
{
	if (power == 1) return nb % mod;

	ll result = rec_pow(nb, power/2, mod);
	result = result * result % mod;

	if (power % 2 == 0) return result;
	return result * nb % mod;
}

// long long func1(long long nb, long long power, long long mod) // 재귀 - 메모리 초과
// {
// 	if (power == 1) return nb % mod;
// 	return (nb * func1(nb, power - 1, mod) % mod);
// }

// long long func2(long long nb, long long power, long long mod) // 반복 - 시간초과
// {
// 	int result = 1;
// 	while(power--) result = result * nb % mod;
// 	return result;
// }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	// cout << func1(a, b/2, c);
	// if (b > 1)
	// 	cout << a * a % c;
	// else
	// 	cout << a % c;
	cout << rec_pow(a, b, c);
}