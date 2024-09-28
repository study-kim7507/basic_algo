// 원소간의 대소관계가 주어지고, 순서를 정해야 한다 -> 위상정렬

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[1001];

long long indegree[1001];
queue<int> zero;

vector<int> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, prev;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			if (j == 0) cin >> prev;
			else
			{
				int c;
				cin >> c;
				adj[prev].push_back(c);
				indegree[c]++;
				prev = c;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) zero.push(i);

	while (!zero.empty())
	{
		int cur = zero.front(); zero.pop();
		result.push_back(cur);
		for (int nxt : adj[cur])
			if (--indegree[nxt] == 0) zero.push(nxt);
	}

	if (result.size() != n)
	{
		cout << 0 << "\n";
		return 0;
	}

	for (const int& element : result)
		cout << element << "\n";

	return 0;
}