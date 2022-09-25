#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 10804번 문제

int main()
{
    vector<int> v(20);
    int a, b;
    for (int i = 0; i < 20; i++)
        v[i] = i + 1;
    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        reverse(v.begin() + a - 1, v.begin() + b);
        
    }
    for (int i : v)
        cout << i << " ";
}