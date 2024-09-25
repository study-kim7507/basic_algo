#include <iostream>
#include <algorithm>
using namespace std;

int cards[500001];
int inputs[500001];

int lb(int st, int en, int target)
{
	if (st >= en) return st;
	int mid = (st + en) / 2;
	if (cards[mid] >= target) return lb(st, mid, target);
	else return lb(mid + 1, en, target);
}

int ub(int st, int en, int target)
{
	if (st >= en) return st;
	int mid = (st + en) / 2;
	if (cards[mid] > target) return ub(st, mid, target);
	else return ub(mid + 1, en, target);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cards[i];

	sort(cards, cards + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> inputs[i];

	for (int i = 0; i < m; i++)
		cout << ub(0, n, inputs[i]) - lb(0, n, inputs[i]) << " ";
	cout << "\n";

	return 0;
}