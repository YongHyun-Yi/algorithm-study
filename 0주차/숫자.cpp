#include <iostream>
using namespace std;

// 백준 10093번 문제

int main()
{
    ios_base::sync_with_stdio(false);
    
    long long a, b, temp;
    cin >> a >> b;
    
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    
    if (a == b)
        cout << 0;
    else
        cout << (b - a) - 1 << '\n';
        for (long long i = a + 1; i < b; i++)
            cout << i << " ";
}