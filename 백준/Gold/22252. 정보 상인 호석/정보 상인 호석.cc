// BOJ_22252. 정보 상인 호석
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

unordered_map<string, priority_queue<int>> um;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long answer = 0;

	int q;
	cin >> q;
	while (q--)
	{
		int cmd, k;
		string name;
		
		cin >> cmd >> name;
		if (cmd == 1)
		{
			int k;
			cin >> k;
			for (int i = 0; i < k; i++)
			{
				int c;
				cin >> c;
				um[name].push(c);
			}
		}
		else if (cmd == 2)
		{
			int b;
			cin >> b;
			for (int i = 0; i < b; i++)
			{
				if (um[name].empty()) break;
				answer += um[name].top();
				um[name].pop();
			}
		}
	}


	std::cout << answer << "\n";

	return 0;
}