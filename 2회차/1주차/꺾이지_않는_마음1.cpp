// 백준 26142번 문제

#include <iostream>
#include <algorithm>
#include <vector>

#define D first
#define H second

using namespace std;

vector<pair<long long, long long>> dragons;
vector<vector<pair<long long, int>>> dp;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		long long d, h;

		cin >> d >> h;
		dragons.push_back({d, h});
	}

	
}

// ---------------------------------

// #include <iostream>
// #include <algorithm>
// #include <vector>

// #define CURRENT first
// #define DEC second
// #define D first
// #define H second

// using namespace std;

// vector<pair<long long, long long>> dragons;
// long long result[10000];

// bool cmp(pair<int, int> a, pair<int, int> b)
// {
// 	if (a.D > b.D && a.H > b.H) return true;
// 	else if (a.D == b.D && a.H > b.H) return true;
// 	else if (a.D > b.D && a.H == b.H) return true;
// 	else return false;
// }

// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n;
// 	long long a, b;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> a >> b;
// 		dragons.push_back({a, b});
// 	}

	// sort(dragons.begin(), dragons.end(), cmp);

	// result[0] = dragons[0].H;
	// for (int i = 1; i < n; i++)
	// {
	// 	result[i] = dragons[i].H + result[i - 1];
	// 	for (int j = i - 1; j >= 0; j--) result[i] += dragons[j].D;
	// }

	// for (int i = 0; i < n; i++)
	// 	cout << result[i] << '\n';

	// sort(dragons.begin(), dragons.end());

	// result[0] = dragons[n - 1].H;
	// for (int i = 1; i < n; i++)
	// {
	// 	result[i] = dragons[n - 1 - i].H + result[i - 1];
	// 	for (int j = n - i; j < n; j++) result[i] += dragons[j].D;
	// }

	// for (int i = 0; i < n; i++)
	// 	cout << result[i] << '\n';


// 	for (int i = 0; i < n; i++) // D를 곱하는수
// 	{
// 		vector<pair<long long, long long>> temp;
// 		long long result = 0;
// 		for (int j = 0; j < n; j++) // 용의 인덱스
// 			temp.push_back({dragons[j].H + (dragons[j].D * i), dragons[j].D});
		
// 		for (int j = i; j >= 0; j--)
// 		{
// 			sort(temp.begin(), temp.end());
// 			result += temp[temp.size() - 1].CURRENT;
// 			temp.pop_back();

// 			for (int k = 0; k < temp.size(); k++)
// 				temp[k].CURRENT -= temp[k].DEC;
// 		}

// 		cout << result << '\n';
// 	}
// }

/*
	증가량이 적은것부터 먼저 잘라냄, 이후 오름차순으로 반복
	증가량이 큰건 같은날이 지나도 더 켜져있음
	그냥 제일큰걸 연속으로 자르면 되는거 아닌가...?

	atm 문제랑 비슷한거같기도...?

	1. 우선 정렬
	2. 큰애부터 result += (D *(i - 1)) + H 내림차순으로 반복...

	i == 1, H[1]
	i == 2, H[2] + H[1] + D[1]
	i == 3, H[3] + H[2] + D[2] + H[1] + D[1] + D[1]
	i == 4, H[4] + H[3] + D[3] + H[2] + D[2] + D[2] + H[1] + D[1] + D[1] + D[1]

	이전값 + 현재H + 이전까지의 D 하나씩 더하기

	------------

	수정 D와 H에 따라서 N일차마다 sort했을때 순서가 달라질수있음
	항상 같은 순서가 보장되지 않음, 매번 계산하고나서 정렬해야함
	h에 d를 0~n만큼 더한걸 미리 배열로 만들어두기?

	→ 시간초과 발생, DP로 활용하려면...?

	[용 인덱스][D를 더해준 수] = n - 1 일차때 용의 길이, D를 더해준수 = n - 1
*/