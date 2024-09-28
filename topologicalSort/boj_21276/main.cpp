#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<string> people;
map<string, vector<string>> adj;
map<string, int> indegree;

vector<string> root;
map<string, vector<string>> result;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		people.push_back(name);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		indegree[u]++;
	}

	queue<string> zero;
	for (int i = 0; i < people.size(); i++)
	{
		if (indegree[people[i]] == 0)
		{
			zero.push(people[i]);
			root.push_back(people[i]);
		}
	}
		
	while(!zero.empty())
	{
		auto cur = zero.front(); zero.pop();
		for (auto nxt : adj[cur])
		{
			if (--indegree[nxt] == 0)
			{
				result[cur].push_back(nxt);
				zero.push(nxt);
			}
		}
	}

	// 시조들 정렬
	sort(root.begin(), root.end());

	// 사람들 정렬
	sort(people.begin(), people.end());

	cout << root.size() << "\n";
	for (const auto& element : root)
		cout << element << " ";
	cout << "\n";

	for (auto cur : people)
	{
		// 찾지 못한 것이면 자식이 없는 것임
		if (result.find(cur) == result.end())
		{
			cout << cur << " " << 0 << "\n";
			continue;
		}

		// 찾았을 경우, 사전순으로
		cout << cur << " ";
		cout << result[cur].size() << " ";
		sort(result[cur].begin(), result[cur].end());
		for (const auto& element : result[cur])
			cout << element << " ";
		cout << "\n";
	}
	return 0;
}