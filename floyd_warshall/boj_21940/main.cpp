#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dist[201][201];
const int INF = 987654321;

int k;
vector<int> c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		fill(dist[i], dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
		

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		c.push_back(num);
	}

	vector<int> result;
	int min_time = INF;
	for (int i = 1; i <= n; i++)
	{
		vector<int> aroundTime;
		for (const int& j : c)
		{
			int sum = 0;
			sum += dist[i][j];
			sum += dist[j][i];
			aroundTime.push_back(sum);
		}

		
		int max_aroundTime = *max_element(aroundTime.begin(), aroundTime.end());
		if (min_time > max_aroundTime)
		{
			result.clear();
			result.push_back(i);
			min_time = max_aroundTime;
		}
		else if (min_time == max_aroundTime)
			result.push_back(i);
	}

	sort(result.begin(), result.end());
	for (const auto& element : result)
		cout << element << " ";

	return 0;
}
