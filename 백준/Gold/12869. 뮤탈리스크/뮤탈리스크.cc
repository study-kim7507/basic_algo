// BOJ_12869. 뮤탈리스크
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
using namespace std;

int n;

int scv[3];
tuple<int, int, int> attack[6] =
{
	make_tuple(1, 3, 9),
	make_tuple(1, 9, 3),
	make_tuple(3, 1, 9),
	make_tuple(3, 9, 1),
	make_tuple(9, 1, 3),
	make_tuple(9, 3, 1)
};

map<tuple<int, int, int>, int> vis;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> scv[i];

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(scv[0], scv[1], scv[2]));
	vis[make_tuple(scv[0], scv[1], scv[2])] = 1;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 6; i++)
		{
			int a = max(get<0>(cur) - get<0>(attack[i]), 0);
			int b = max(get<1>(cur) - get<1>(attack[i]), 0);
			int c = max(get<2>(cur) - get<2>(attack[i]), 0);

			if (vis[make_tuple(a, b, c)] != 0) continue;
			vis[make_tuple(a, b, c)] = vis[cur] + 1;
			q.push(make_tuple(a, b, c));
		}
	}

	std::cout << vis[make_tuple(0, 0, 0)] - 1<< "\n";
	return 0;
}