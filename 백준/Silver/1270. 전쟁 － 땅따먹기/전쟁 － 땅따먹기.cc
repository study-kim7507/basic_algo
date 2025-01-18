// 1270. 전쟁 - 땅따먹기
#include <iostream>
#include <vector>
#include <unordered_map>
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
		int t;
		cin >> t;

		bool isOccupied = false;
		unordered_map<long, int> m;
		for (int i = 0; i < t; i++)
		{
			long num;
			cin >> num;
			m[num]++;

			if (m[num] > t / 2 && !isOccupied)
			{
				cout << num << "\n";
				isOccupied = true;
			}
		}
		if (!isOccupied) cout << "SYJKGW" << "\n";
	}

	return 0;
}