// 1374. 강의실
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num, st, en;
		cin >> num >> st >> en;
		v.push_back(make_pair(st, en));
	}

	// 강의를 시작 시간 기준 오름차순 정렬
	// 시작 시간이 동일한 경우 종료 시간 기준 오름차순 정렬
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	for (const auto& e : v)
	{
		if (pq.empty()) pq.push(e.second);
		else
		{
			while(!pq.empty() && (pq.top() <= e.first)) pq.pop();
			pq.push(e.second);
		}

		if (result <= pq.size()) result = pq.size();
	}

	cout << result << "\n";
	return 0;
}