#include <iostream>
using namespace std;

// ���� 8393�� ����

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