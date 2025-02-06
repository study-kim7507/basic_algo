// 6263. 용돈 관리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> money;

bool check(long long k)
{
	long long remain = k;
	int cnt = 1;
	for (int i = 0; i < money.size(); i++)
	{
		if (remain < money[i])
		{
			remain = k;
			if (remain < money[i]) return false;
			cnt++;
		}
		remain -= money[i];
	}
	return cnt <= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		money.push_back(num);
	}

	long long st = 0;
	long long en = 1000000000;
	long long result = 0;
	
	while (st <= en)
	{
		long long mid = (st + en) / 2;
		if (check(mid))
		{
			result = mid;
			en = mid - 1;	
		}
		else
		{
			st = mid + 1;
		}
	}

	cout << result << "\n";
	return 0;
}