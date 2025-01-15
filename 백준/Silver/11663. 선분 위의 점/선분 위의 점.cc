// 11663. 선분 위의 점
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;

		cout << upper_bound(v.begin(), v.end(), en) - lower_bound(v.begin(), v.end(), st) << "\n";
	}

	return 0;
}