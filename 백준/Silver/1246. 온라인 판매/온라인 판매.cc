// 1246. 온라인 판매
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> v;
priority_queue<int> pq;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		v.push_back(p);
		pq.push(p);
	}

	int count = 0;
	int price = 0;
	sort(v.rbegin(), v.rend());

	while (!pq.empty())
	{
		int remain = n;				// 남은 달걀의 개수
		int tmpResult = 0;			// 현재 가격으로 달걀을 팔았을 때 얻을 수 있는 수익
		
		auto cur = pq.top(); pq.pop();	// 현재 가격
		
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= cur)
			{
				tmpResult += cur;
				remain--;
			}
			if (remain <= 0) break;
		}
		if (price <= tmpResult)
		{
			count = cur;
			price = tmpResult;
		}
	}

	cout << count << " " << price << "\n";

	return 0;
}