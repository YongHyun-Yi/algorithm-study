#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 2587번 문제

int main()
{
    vector<int> a(5);
    int avg = 0, cent;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg /= 5;
    sort(a.begin(), a.end());
    cent = a[2];
    cout << avg << '\n' << cent;
}