#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[500001];
int inputs[500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cards[i];

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> inputs[i];

	sort(cards, cards + n);
	for (int i = 0; i < m; i++)
	{
		if (binary_search(cards, cards + n, inputs[i]))
			cout << 1 << " ";
		else cout << 0 << " ";
	}
	
	return 0;
}