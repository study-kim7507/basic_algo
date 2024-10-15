#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, k;
deque<int> belt;			// 벨트의 내구도
bool robot[101];					// 로봇이 존재하는지 여부

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++)
	{
		int a;
		cin >> a;
		belt.push_back(a);			// 벨트의 내구도 입력
	}

	int ans = 1;
	for (ans = 1; ; ans++)
	{
		// 벨트 회전
		belt.push_front(belt.back());
		belt.pop_back();

		// 로봇 회전
		for (int i = n - 1; i >= 1; i--)
		{
			robot[i] = robot[i - 1];
			robot[i - 1] = false;
		}
		robot[n - 1] = false;			// 회전 후 내리는 위치에 로봇은 바로 내림

		// 로봇 이동
		for (int i = n - 2; i >= 0; i--)
		{
			// 이동하려는 칸에 로봇이 있거나, 내구도가 0이하인 경우 이동하지 않음 
			if ((belt[i + 1] <= 0) || (robot[i + 1] == true) || robot[i] == false) continue;
			robot[i + 1] = robot[i];
			robot[i] = false;
			belt[i + 1]--;
		}
		robot[n - 1] = false;			// 이동 후 내리는 위치에 로봇은 바로 내림

		if (belt[0] > 0)
		{
			belt[0]--;
			robot[0] = true;		// 올리는 위치에 로봇 올림
		}

		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
			if (belt[i] <= 0) cnt++;
		
		if (cnt >= k) break;
	}

	cout << ans << "\n";
	return 0;
}