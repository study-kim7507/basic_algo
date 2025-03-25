// 2251. 물통
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;


int water[3];
int bucket[3];
int from[6] = { 0, 1, 0, 2, 1, 2 };
int to[6] = { 1, 0, 2, 0, 2, 1 };
bool vis[201][201];
vector<int> result;

int main()
{
	cin >> water[0] >> water[1] >> water[2];

	bucket[0] = water[0];
	bucket[1] = water[1];
	bucket[2] = water[2];

	queue<vector<int>> q;
	q.push({ 0, 0, water[2]});
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int f = from[dir];
			int t = to[dir];

			auto cpy = cur;

			int diff = bucket[t] - cpy[t];

			if (diff > cpy[f])
			{
				diff = cpy[f];
				cpy[f] = 0;
				cpy[t] += diff;
			}
			else
			{
				cpy[f] -= diff;
				cpy[t] += diff;
			}

			if (vis[cpy[0]][cpy[1]]) continue;

			vis[cpy[0]][cpy[1]] = true;
			q.push(cpy);

			if (cpy[0] == 0) result.push_back(cpy[2]);
		}
	}

	sort(result.begin(), result.end());
	for (auto c : result)
		cout << c << "\n";
	

	return 0;
}
