// 전체 치킨 집 중, 폐업시키지 않을 M개의 치킨집을 고름.
// 도시의 치킨 거리를 계산
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int board[51][51];

vector<int> combi;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int ans = 987654321;

void calChickenDist(vector<int> selected)
{
	int result = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int min = 987654321;
		for (int j = 0; j < selected.size(); j++)
		{
			int dist = abs(house[i].first - chicken[selected[j]].first) +
				abs(house[i].second - chicken[selected[j]].second);
			if (min > dist) min = dist;
		}
		result += min;
	}

	if (ans > result) ans = result;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2)
			{
				combi.push_back(0);
				chicken.push_back({ i, j });
			}	
		}
	}

	for (int i = combi.size() - 1; i >= m; i--)
		combi[i] = 1;

	do
	{
		vector<int> selected;
		for (int i = 0; i < combi.size(); i++)
			if (combi[i] == 0) selected.push_back(i);
		calChickenDist(selected);

	} while (next_permutation(combi.begin(), combi.end()));

	cout << ans << "\n";
	return 0;
}
