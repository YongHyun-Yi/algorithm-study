#include <iostream>
using namespace std;

// ���� 2739�� ����

int main()
{
    int n;
    int i;
    cin >> n;
    i = 1;
    while (i <= 9)
    {
        cout << n << " * " << i << " = " << n * i << endl;
        i++;
    }
    return 0;
}