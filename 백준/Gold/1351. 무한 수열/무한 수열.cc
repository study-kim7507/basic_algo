// BOJ_1351. 무한수열
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long n, p, q;

unordered_map<long long, long long> um;

long long dfs(long long i)
{
	if (um[i] != 0) return um[i];
	if (i == 0)
		return 1;

	double ip = double(i) / p;
	double iq = double(i) / q;

	um[i] = dfs(ip) + dfs(iq);
	return um[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> p >> q;
	cout << dfs(n) << "\n";

	return 0;
}