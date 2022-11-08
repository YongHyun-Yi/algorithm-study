// 백준 2217번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int result = 0;
	for (int k = 1; k <= n; k++) // n - i 가 0 ~ 4 가 될수있도록 조절
		result = max(result, arr[n - k] * k);
	
	cout << result;
}

// 영상 해설을 보면 k개를 고르는 식이 w[n-k] * k 라고 하는데
// 갑자기 식만 뚝하고 나와버리니 이유를 모르겠음...
//
// 일단 로프를 길이별로 정렬 한 후 고른 밧줄중에서 가장 짧은
// 밧줄에다가 고른 밧줄의 수만큼 곱해주는것같음
// 밧줄 수만큼 나누던 평균을 내던 뭘하던간에 결국
// 그 밧줄들이 들수있는 최대 중량은
// 가장 짧은 밧줄이 들수있는 중량일것이기 때문에
// 그냥 평균값을 낸다면 그것보단 크게 나오겠지만
// 그러면 제일 짧은 밧줄이 들수없음
// 최대중량을 구해야 하기때문에 최댓값을 구해야한다는 생각떄문에
// 헛갈릴수도 있을것같음
// 각각의 밧줄에 걸리는 부하는 밧줄의 평균값으로 들어감
// 그렇기에 값이 작아지면 작아지지 커지지는 않음