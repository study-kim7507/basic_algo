// 유니온 파인드
#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int uf_find(int x)
{
	if (parent[x] != x)
		return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;


	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;

		switch (cmd)
		{
		case 0:
			uf_union(a, b);
			break;
		case 1:
			if (uf_find(a) == uf_find(b)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
			break;
		}
	}


	return 0;
}