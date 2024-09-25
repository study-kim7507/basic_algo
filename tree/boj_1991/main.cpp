#include <iostream>
using namespace std;

int n;
int idx_lc[27];
int idx_rc[27];
char lc[27];
char rc[27];

void preorder(char cur)
{
	cout << cur;
	if (lc[cur - 'A'] != '.') preorder(lc[cur - 'A']);
	if (rc[cur - 'A'] != '.') preorder(rc[cur - 'A']);
}

void inorder(char cur)
{
	if (lc[cur - 'A'] != '.') inorder(lc[cur - 'A']);
	cout << cur;
	if (rc[cur - 'A'] != '.') inorder(rc[cur - 'A']);
}

void postorder(char cur)
{
	if (lc[cur - 'A'] != '.') postorder(lc[cur - 'A']);
	if (rc[cur - 'A'] != '.') postorder(rc[cur - 'A']);
	cout << cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(lc, lc + 27, '.');
	fill(rc, rc + 27, '.');

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		lc[a - 'A'] = b;
		rc[a - 'A'] = c;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}
