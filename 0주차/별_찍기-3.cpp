#include <iostream>
using namespace std;

// ���� 2440�� ����

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}