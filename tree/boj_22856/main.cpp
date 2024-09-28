#include <iostream>
#include <vector>
using namespace std;

int n;
int parent[100001];
int lc[100001];
int rc[100001];
int ans = 0;
bool vis[100001];
int en;


void similar_inorder(int cur)
{
	vis[cur] = true;
	// cout << cur << " ";
	ans++;
	if (lc[cur] != -1 && vis[lc[cur]] == false) similar_inorder(lc[cur]);
	else if (rc[cur] != -1 && vis[rc[cur]] == false) similar_inorder(rc[cur]);
	else if (cur == en) return;
	else if (parent[cur] != 0) similar_inorder(parent[cur]);
}

// 중위 순회의 끝을 구하기 위함
void inorder(int cur)
{
	if (lc[cur] != -1) inorder(lc[cur]);
	en = cur;
	if (rc[cur] != -1) inorder(rc[cur]);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
		
		if (b != -1) parent[b] = a;
		if (c != -1) parent[c] = a;
	}

	inorder(1);
	similar_inorder(1);

	cout << ans - 1 << "\n";

	return 0;
}