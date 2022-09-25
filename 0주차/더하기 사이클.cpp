#include <iostream>
using namespace std;

// 백준 1110번 문제

int main()
{
    int n, count = 0, temp, a, b;
    cin >> n;
    temp = n;
    while (true)
    {
        a = temp / 10;
        b = temp % 10;
        temp = (b * 10) + ((a + b) % 10);
        count++;
        if (temp == n)
            break;
    }
    cout << count;
    return 0;
}