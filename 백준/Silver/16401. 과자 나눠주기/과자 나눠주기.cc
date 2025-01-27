// 16401. 과자 나눠주기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<long long> snacks;

long long solve(long long length)
{
	long long cnt = 0;
	for (const auto& e : snacks)
		cnt += (e / length);
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	
	long long st = 1;
	long long en = 0;
	for (int i = 0; i < n; i++)
	{
		long long l;
		cin >> l;
		snacks.push_back(l);
		en = max(en, l);
	}

	while (st <= en)
	{
		long long mid = (st + en) / 2;
		if (solve(mid) >= m) st = mid + 1;
		else en = mid - 1;
	}
	
	cout << st - 1 << "\n";

	return 0;
}