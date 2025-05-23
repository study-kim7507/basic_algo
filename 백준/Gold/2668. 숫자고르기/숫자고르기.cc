// BOJ_2688. 숫자고르기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int edges[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		edges[i] = num;
	}
	
	set<int> answer;
	for (int i = 1; i <= n; i++)
	{
		vector<bool> vis(n + 1, false);

		queue<int> q;
		q.push(i);
		vis[i] = true;

		bool isCycle = false;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			int nxt = edges[cur];

			if (vis[nxt] && nxt == i)
			{
				vis[nxt] = true;
				isCycle = true;
				break;
			}
			else if (vis[nxt] && nxt != i) break;

			vis[nxt] = true;
			q.push(nxt);
		}

		if (isCycle)
		{
			for (int j = 1; j <= n; j++)
			{
				if (vis[j]) answer.insert(j);
			}
		}
	}

	std::cout << answer.size() << "\n";
	for (auto it = answer.begin(); it != answer.end(); it++)
		std::cout << (*it) << "\n";
	return 0;
}