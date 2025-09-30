// BOJ_1043 거짓말
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[51];
vector<int> parties[51];
int ans = 0;

int uf_find(int x)
{
	if (x != parent[x]) return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int u = uf_find(x);
	int v = uf_find(y);

	if (u <= v) parent[v] = u;
	else parent[u] = v;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= 50; i++)
		parent[i] = i;

	int knownPersonCount = 0;
	cin >> knownPersonCount;
	for (int i = 0; i < knownPersonCount; i++)
	{
		int knownPerson;
		cin >> knownPerson;
		uf_union(knownPerson, 0);
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		vector<int> newParty(num, 0);

		for (int j = 0; j < num; j++)
			cin >> newParty[j];
		for (int j = 1; j < num; j++)
			uf_union(newParty[j - 1], newParty[j]);

		parties[i] = newParty;
	}

	for (int i = 0; i < m; i++)
	{
		vector<int> curParty = parties[i];
		bool isInKnownPerson = false;

		for (int j = 0; j < curParty.size(); j++)
		{
			if (uf_find(curParty[j]) == 0)
			{
				isInKnownPerson = true;
				break;
			}
		}

		if (!isInKnownPerson)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}