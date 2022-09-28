// 백준 5430번 문제

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		string cmd, input_arr;
		int size, temp = 0, error = 0, rev = 0;
		cin >> cmd >> size >> input_arr;

		deque<int> que;
		for (int i = 1; i + 1 < input_arr.size(); i++)
		{
			if (input_arr[i] == ',')
			{
				que.push_back(temp);
				temp = 0;
			}
			else temp = temp * 10 + (input_arr[i] - '0');
		}
		if (temp != 0) que.push_back(temp); // 사이즈가 0 일떄의 예외처리가 문제였으나 변경전 예외처리랑 무슨 차이인지 모르겠음...

		for (char c : cmd)
		{
			if (c == 'R') rev = 1 - rev; // 이런식으로 토글할수있다

			else if (c == 'D')
			{
				if (que.empty())
				{
					error = 1;
					break;
				}
				else
				{
					if (rev) que.pop_back();
					else que.pop_front();
					size--;
				}
			}
		}
		if (error) cout << "error\n";
		else
		{
			if (rev) reverse(que.begin(), que.end());

			cout << '[';
			while (size--)
			{
				cout << que.front();
				if (size > 0)
					cout << ',';
				que.pop_front();
			}
			cout << "]\n";
		}
	}
}

// 매번 배열을 복사해서 뒤집는게 아니라
// 뒤집기 명령을 int변수에 토글처럼 받아서
// 앞에서 뺄지 뒤에서 뺄지를 결정
// 나중에 출력하기전에만 뒤집을지 말지 실행하고
// 한번에 출력함으로써 시간초과를 피할수있음
// --------------------------