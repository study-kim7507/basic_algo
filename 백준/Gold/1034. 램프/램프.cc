// BOJ_1034. 램프
// 모든 행에 대해서 램프를 모두 키는 켰을 때, 해당 행과 동일한 행의 개수 파악
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int n, m, k;
vector<string> table;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		table.push_back(str);
	}
	cin >> k;


	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		string cur = table[i];
		int zeroCount = 0;
		for (int j = 0; j < cur.size(); j++)
		{
			if (cur[j] == '0') zeroCount++;
		}

		if (zeroCount <= k && zeroCount % 2 == k % 2)
		{
			int sameCount = 0;
			for (const auto& e : table)
			{
				if (e == cur) sameCount++;
			}

			answer = max(answer, sameCount);
		}
	}

	std::cout << answer << "\n";
	return 0;
}