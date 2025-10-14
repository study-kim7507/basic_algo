// BOJ 16953. A->B
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	unordered_map<long long, int> visit;
	queue<long long> q;

	visit[a] = 0;
	q.push(a);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : { cur * 2, cur * 10 + 1 })
		{
			if (nxt > b) continue;
			if (visit.find(nxt) != visit.end()) continue;

			visit[nxt] = visit[cur] + 1;
			q.push(nxt);
		}
	}

	if (visit.find(b) == visit.end()) std::cout << -1 << "\n";
	else std::cout << visit[b] + 1 << "\n";

	return 0;
}