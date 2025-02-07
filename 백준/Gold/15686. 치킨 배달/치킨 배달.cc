// 15686. 치킨 배달
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[51][51];

vector<int> combi;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) houses.push_back({ i, j });
			else if (board[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	for (int i = 0; i < chickens.size(); i++)
	{
		if (i < m) combi.push_back(1);
		else combi.push_back(0);
	}


	int result = 987654321;
	do
	{ 
		int tempResult = 0;
		for (int i = 0; i < houses.size(); i++)
		{
			int dist = 987654321;
			for (int j = 0; j < chickens.size(); j++)
			{
				if (combi[j] == 1)
				{
					int curDist = (abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second));
					dist = min(dist, curDist);
				}
			}
			tempResult += dist;
		}
		result = min(result, tempResult);
	} while (prev_permutation(combi.begin(), combi.end()));

	cout << result << "\n";
	
	return 0;
}