// 7795. 먹을 것인가 먹힐 것인가
#include <iostream>
#include <queue>
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
		priority_queue<int> a;
		priority_queue<int> b;

		int n, m, input;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			a.push(input);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> input;
			b.push(input);
		}

		int result = 0;
		while (!a.empty())
		{
			int cur = a.top(); a.pop();
			while (!b.empty() && cur <= b.top()) b.pop();
			result += b.size();
		}
		
		cout << result << "\n";
	}

	return 0;
}