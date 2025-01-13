// 2776. 암기왕
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> note1;
		int n, m;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			note1.push_back(num);
		}

		sort(note1.begin(), note1.end());

		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;
			if (binary_search(note1.begin(), note1.end(), num))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}


	return 0;
}