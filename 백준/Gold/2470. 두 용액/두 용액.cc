// 2470. 두 용액
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

long long m = 2000000001;
pair<int, int> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		long long sum = 0;

		auto it = lower_bound(v.begin(), v.end(), -v[i]);
		if (it == v.end())
		{
			for (auto e : { it - 2, it - 1 })
			{
				if (e == v.end() || v[i] == *e) continue;
				sum = abs(*e + v[i]);
				if (sum <= m)
				{
					m = sum;
					if (v[i] < *e) result = make_pair(v[i], *e);
					else result = make_pair(*e, v[i]);
				}
			}
		}
		else if (it == v.begin())
		{
			for (auto e : { it, it + 1, it + 2})
			{
				if (e == v.end() || v[i] == *e) continue;
				sum = abs(*e + v[i]);
				if (sum <= m)
				{
					m = sum;
					if (v[i] < *e) result = make_pair(v[i], *e);
					else result = make_pair(*e, v[i]);
				}
			}
		}
		else
		{
			for (auto e : { it - 1, it, it + 1 })
			{
				if (e == v.end() || v[i] == *e) continue;
				sum = abs(*e + v[i]);
				if (sum <= m)
				{
					m = sum;
					if (v[i] < *e) result = make_pair(v[i], *e);
					else result = make_pair(*e, v[i]);
				}
			}
		}

		
	}

	cout << result.first << " " << result.second << "\n";

	return 0;
}

// -99 -4 -2 -1 98