// 시작 정점 K에서 모든 정점을 방문하는데 걸리는 최단 시간 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int t[11][11];

bool vis[11];
int result = 987654321;
void dfs(int cur, int cnt, int sum)
{
	if (cnt == n)
	{
		if (result > sum) result = sum;
		return;
	}

	vis[cur] = true;
	for (int i = 0; i < n; i++)
	{
		if (cur == i) continue;
		if (vis[i] == true) continue;
		dfs(i, cnt + 1, sum + t[cur][i]);
	}
	vis[cur] = false;
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> t[i][j];
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				t[i][j] = min(t[i][k] + t[k][j], t[i][j]);

	dfs(m, 1, 0);
	cout << result << "\n";
	return 0;
}