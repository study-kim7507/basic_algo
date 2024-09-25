// 최소값을 계속 더해나감 -> 최소힙, 이진 탐색 트리

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	long long ans = 0;
	while (pq.size() != 1)
	{
		long long temp = 0;
		temp += pq.top(); pq.pop();
		temp += pq.top(); pq.pop();
		ans += temp;
		pq.push(temp);
	}
	

	cout << ans << "\n";
	return 0;
}
