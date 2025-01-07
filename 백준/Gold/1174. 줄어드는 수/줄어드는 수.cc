// 1174. 줄어드는 수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;

void solve(int prev, string cur)
{
	v.push_back(stoll(cur));
	if (prev <= 0) return;

	for (int i = prev - 1; i >= 0; i--)
	{
		solve(i, cur + to_string(i));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < 10; i++)
		solve(i, to_string(i));
	
	sort(v.begin(), v.end());
	if (v.size() >= n) cout << v[n - 1] << "\n";
	else cout << -1 << "\n";

	return 0;
}