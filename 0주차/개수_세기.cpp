#include <iostream>
#include <vector>
using namespace std;

// 백준 10807번 문제

int main()
{
    int n, x, v;
    vector<int> arr(201);
    cin >> n;
    while(n)
    {
        cin >> x;
        arr[x + 100]++;
        n--;
    }
    cin >> v;
    cout << arr[v + 100];
}