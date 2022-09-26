#include <iostream>
#include <vector>
using namespace std;

// 백준 3273번 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x, nb, count = 0;
	cin >> n;
	vector<int> arr;
	vector<int> check_arr(2000000);
	while (n)
	{
		cin >> nb;
		arr.push_back(nb);
		n--;
	}
	cin >> x;
	for (int i : arr)
	{
		if (x - i > 0 && check_arr[x - i] > 0)
			count++;
		check_arr[i]++;
	}
	cout << count;
	return 0;
}