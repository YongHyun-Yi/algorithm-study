#include <iostream>
using namespace std;

// 백준 15552번 문제

int main()
{
    int t, a, b;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (t; t > 0; t--)
    {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}