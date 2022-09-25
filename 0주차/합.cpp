#include <iostream>
using namespace std;

// 백준 8393번 문제

int main()
{
    int n;
    int result;
    
    cin >> n;
    result = 0;
    
    while (n > 0)
    {
        result += n;
        n--;
    }
    cout << result;
    return 0;
}