// 2343. 기타 레슨
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> lecs;

bool solve(long long length)
{
	long long cur = 0;
	vector <long long> tmp;

	for (long long lec : lecs)
	{
		if (cur + lec > length)
		{
			tmp.push_back(cur);
			cur = 0;
		}
		cur += lec;
	}
	if (cur != 0) tmp.push_back(cur);

	return tmp.size() <= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	long long st = 0;
	long long en = 0;

	for (int i = 0; i < n; i++)
	{
		long long lec;
		cin >> lec;
		lecs.push_back(lec);

		st = max(st, lec);
		en += lec;
	}

	long long result = 0;

	while (st <= en)
	{
		long long mid = (st + en) / 2;

		if (solve(mid))
		{
			en = mid - 1;
			result = mid;
		}
		else st = mid + 1;
	}

	cout << result << "\n";

	return 0;
}