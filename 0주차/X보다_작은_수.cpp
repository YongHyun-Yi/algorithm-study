#include <iostream>
using namespace std;

// 백준 10871번 문제

int main()
{
    int n, x, a;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    while (n)
    {
        cin >> a;
        if (a < x)
            cout << a << " ";
        n--;
    }
    return 0;
}