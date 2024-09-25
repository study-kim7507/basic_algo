#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--)
	{
		int num;
		int n, m;
		vector<int> a;
		vector<int> b;
		cin >> n >> m;

		while (n--)
		{
			cin >> num;
			a.push_back(num);
		}
		while (m--)
		{
			cin >> num;
			b.push_back(num);
		}

		sort(a.rbegin(), a.rend());
		// a.erase(unique(a.begin(), a.end()), a.end());
		sort(b.rbegin(), b.rend());
		// b.erase(unique(b.begin(), b.end()), b.end());

		int ans = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] <= b[b.size() - 1]) break;
			for (size_t j = 0; j < b.size(); j++)
			{
				if (a[i] > b[j]) ans++;
			}
		}
			
		cout << ans << "\n";
	}

	return 0;
}