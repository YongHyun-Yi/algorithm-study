#include <iostream>
#include <algorithm>
using namespace std;

// ���� 10808�� ����

int main()
{
    int arr[26];
    fill(arr, arr+26, 0);
    string str;
    cin >> str;
    for (char c : str)
        arr[c - 'a']++;
    for (int a : arr)
        cout << a << " ";
    return 0;
}