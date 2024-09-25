#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nA, nB;
long long a[500001];
long long b[500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> nA >> nB;
	for (int i = 0; i < nA; i++)
		cin >> a[i];
	for (int i = 0; i < nB; i++)
		cin >> b[i];

	sort(b, b + nB);

	int cnt = 0;
	vector<long long> result;
	for (int i = 0; i < nA; i++)
	{
		if (!binary_search(b, b + nB, a[i]))
		{
			result.push_back(a[i]);
			cnt++;
		}
	}
	

	if (cnt == 0) cout << 0 << "\n";
	else
	{
		sort(result.begin(), result.end());
		cout << cnt << "\n";
		for (const int& i : result)
			cout << i << " ";
	}
	return 0;
}