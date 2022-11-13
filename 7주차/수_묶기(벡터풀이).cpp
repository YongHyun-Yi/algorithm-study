// 백준 1744번 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec_pos;
vector<int> vec_neg;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, nb;
	long long result = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nb;

		if (nb == 1) result++;
		else if (nb > 1) vec_pos.push_back(nb);
		else vec_neg.push_back(nb);
	}

	sort(vec_pos.begin(), vec_pos.end());
	sort(vec_neg.begin(), vec_neg.end());

	while (vec_pos.size() > 1)
	{
		result += vec_pos[vec_pos.size() - 1] * vec_pos[vec_pos.size() - 2];
		vec_pos.pop_back();
		vec_pos.pop_back();
	}
	if (vec_pos.size() == 1) result += vec_pos[0];

	while (vec_neg.size() > 1)
	{
		result += vec_neg[0] * vec_neg[1];
		vec_neg.erase(vec_neg.begin());
		vec_neg.erase(vec_neg.begin());
	}
	if (vec_neg.size() == 1) result += vec_neg[0];

	cout << result;
}