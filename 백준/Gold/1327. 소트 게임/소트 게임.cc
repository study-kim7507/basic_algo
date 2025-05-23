// BOJ_ 1327. 소트 게임
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> permu;
	map<vector<int>, int> vis;

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		permu.push_back(num);
	}

	queue<vector<int>> q;
	q.push(permu);
	vis[permu] = 1;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 0; i <= n - k; i++)
		{
			vector<int> nxt(cur.begin(), cur.end());
			
			// i 부터 i + k 까지
			reverse(nxt.begin() + i, nxt.begin() + i + k);
		
			if (vis[nxt] != 0) continue;

			/*for (auto e : nxt)
			{
				std::cout << e << " ";
			}
			std::cout << "\n";*/

			vis[nxt] = vis[cur] + 1;
			q.push(nxt);
		}
	}

	sort(permu.begin(), permu.end());
	std::cout << vis[permu] - 1 << "\n";

	return 0;
}