// BOJ_17298. 오큰수
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.push(num);
	}

	stack<int> temp;	// 현재까지의 수 저장
	stack<int> result;
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		while (!temp.empty() && temp.top() <= cur)
			temp.pop();

		if (temp.empty()) result.push(-1);
		else result.push(temp.top());
		temp.push(cur);
	}

	while (!result.empty())
	{
		std::cout << result.top() << " ";
		result.pop();
	}

	return 0;
}