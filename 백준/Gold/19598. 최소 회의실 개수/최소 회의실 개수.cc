// 19598. 최소 회의실 개수
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> sched;

struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		sched.push_back({ st, en });
	}

	sort(sched.begin(), sched.end());
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	int cnt = 1;
	pq.push(sched[0]);
	for (int i = 1; i < sched.size(); i++)
	{
		auto top = pq.top();
		if (top.second <= sched[i].first) pq.pop();
		pq.push(sched[i]);
		cnt = max(cnt, (int)pq.size());
	}

	cout << cnt << "\n";


	return 0;
}