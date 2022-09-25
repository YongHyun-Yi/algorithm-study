#include <iostream>
using namespace std;

// 백준 10430번 문제

int main()
{
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    cout << (a + b) % c << endl;
    cout << ((a % c) + (b % c)) % c << endl;
    cout << (a * b) % c << endl;
    cout << ((a % c) * (b % c)) % c << endl;
    return 0;
}