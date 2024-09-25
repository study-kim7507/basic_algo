#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int input[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;

		fill(input, input + 1000001, 0);
		for (int i = 0; i < k; i++) cin >> input[i];
		sort(input, input + k);

		long long ans = 0;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < k; i++) pq.push(input[i]);
		while (pq.size() != 1)
		{
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}

		cout << ans << "\n";
	}

	return 0;
}