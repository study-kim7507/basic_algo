// BOJ_1101. 카드 정리 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long answer = 0;
	unordered_map<int, int> um;

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		vector<int> box;
		for (int j = 0; j < m; j++)
		{
			int card;
			cin >> card;
			if (card != 0) box.push_back(j);
		}

		if (box.size() >= 2) answer++;
		else if (box.size() == 1) um[box[0]]++;
	}

	int cnt = 0;
	for (auto e : um)
		if (e.second != 1) cnt += (e.second - 1);
	answer += cnt;

	std::cout << max((long long)0, answer - 1) << "\n";

	return 0;
}