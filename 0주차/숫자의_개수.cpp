#include <iostream>
#include <string>
using namespace std;

// 백준 2577번 문제

int main()
{
    int a, b, c, mod;
    int arr[10] = {};
    
    cin >> a;
    cin >> b;
    cin >> c;
    
    mod = a * b * c;
    
    string str = to_string(mod);
    for (char c : str)
    {
        arr[c - '0']++;
    }
    for (int i : arr)
        cout << i << '\n';
    return 0;
    
}