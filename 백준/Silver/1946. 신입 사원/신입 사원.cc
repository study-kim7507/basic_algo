// 1946. 신입 사원 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first > b.first;
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int i = 0; i < n; i++)
		{
			int r1, r2;
			cin >> r1 >> r2;
			pq.push({ r1, r2 });
		}

		int cnt = 0;
		int max = pq.top().second;
		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			if (cur.second <= max)
			{
				cnt++;
				max = cur.second;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}