#include <iostream>
using namespace std;

// 백준 2438번 문제

int main()
{
    int n, i = 1, j = 1;
    cin >> n;
    while (j <= n)
    {
        i = 1;
        while (i <= j)
        {
            cout << "*";
            i++;
        }
        cout << "\n";
        j++;
    }
    return 0;
}