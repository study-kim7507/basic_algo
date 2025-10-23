// BOJ 10986. 나머지 합
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

	vector<long long> prefixSum(n, 0);
	vector<long long> remainder(m, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> prefixSum[i];
		if (i != 0) prefixSum[i] += prefixSum[i - 1];
	
		remainder[prefixSum[i] % m]++;
	}

	long long ans = remainder[0];
	for (int i = 0; i < m; i++)
		ans += (remainder[i] * (remainder[i] - 1)) / 2;
	
	std::cout << ans << "\n";

	return 0; 
}