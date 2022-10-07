#include <iostream>
using namespace std;

// 백준 255304번 문제

int main()
{
	int total;
	int item_size;
	int check_total;
	int price, amount;
	
	cin >> total;
	cin >> item_size;
	
	check_total = 0;
	while (item_size)
	{
		cin >> price >> amount;
		check_total += price * amount;
		item_size--;
	}
	
	if (total == check_total)
		cout << "Yes";
	else
		cout << "No";
}