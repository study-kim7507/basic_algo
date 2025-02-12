// 17503. 맥주 축제
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, k;
vector<pair<int, int>> beers;

struct cmp
{
	bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b)
	{
		return a.second > b.second;
	}
};


priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		long long v, c;
		cin >> v >> c;
		beers.push_back({ c, v });		// {도수, 선호도}
	}

	// 도수 기준 오름차순 정렬
	sort(beers.begin(), beers.end());

	// 누적 선호도
	long long sum = 0;
	for (int i = 0; i < beers.size(); i++)
	{
		auto cur = beers[i];
		pq.push(cur);
		sum += cur.second;

		if (pq.size() > n)
		{
			auto top = pq.top();
			pq.pop();
			sum -= top.second;
		}

		if (pq.size() == n && sum >= m)
		{
			cout << cur.first << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}