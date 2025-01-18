// 1270. 전쟁 - 땅따먹기
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		float t;
		cin >> t;

		map<long, int> m;
		for (int i = 0; i < t; i++)
		{
			long num;
			cin >> num;
			m[num]++;
		}

		long result = 0;
		int cnt = 0;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			auto cur = *it;
			if (cur.second > t / 2)
			{
				result = cur.first;
				cnt++;
			}
		}
		if (cnt == 0 || cnt > 1) cout << "SYJKGW" << "\n";
		else if (cnt == 1) cout << result << "\n";
	}

	return 0;
}