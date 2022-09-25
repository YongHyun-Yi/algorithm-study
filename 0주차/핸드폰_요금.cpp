#include <iostream>
using namespace std;

// 백준 1267번 문제

int main()
{
    int t, n, y = 0, m = 0;
    cin >> t;
    while(t)
    {
        cin >> n;
        y += 10 + (n / 30 * 10);
        m += 15 + (n / 60 * 15);
        t--;
    }
    if (y < m)
        cout << "Y " << y;
    else if (m < y)
        cout << "M " << m;
    else
        cout << "Y M " << y;
    return 0;
}