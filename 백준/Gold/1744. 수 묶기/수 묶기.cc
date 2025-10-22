// BOJ 1744. 수 묶기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int> pos;
	priority_queue<int, vector<int>, greater<int>> neg;
	queue<int> zero;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0) zero.push(num);
		else if (num > 0) pos.push(num);
		else if (num < 0) neg.push(num);
	}

	int ans = 0;

	// 양수 계산
	while (!pos.empty())
	{
		if (pos.size() == 1) ans += pos.top();
		else
		{
			int tempAns = pos.top(); 
			pos.pop();
			tempAns = max(tempAns + pos.top(), tempAns * pos.top());
			ans += tempAns;
		}
		pos.pop();
	}

	// 음수 계산
	while (!neg.empty())
	{
		if (neg.size() == 1)
		{
			if (zero.empty()) ans += neg.top();
		}
		else
		{
			int tempAns = neg.top();
			neg.pop();
			tempAns *= neg.top();
			ans += tempAns;	
		}
		neg.pop();
	}

	std::cout << ans << "\n";
	return 0;
}