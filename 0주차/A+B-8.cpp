#include <iostream>
using namespace std;

// ���� 11022�� ����

int main()
{
    int t, i, a, b;
    cin.tie(NULL);
    cin >> t;
    i = 1;
    while (i <= t)
    {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
        i++;
    }
    return 0;
}