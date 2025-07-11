// BOJ_3151. 합이 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

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

	long long ans = 0;
	for (int first = 0; first < n - 1; first++)
	{
		for (int second = first + 1; second < n; second++)
		{
			int twoSum = v[first] + v[second];
			auto lower = lower_bound(v.begin() + second + 1, v.end(), -twoSum);
			auto upper = upper_bound(v.begin() + second + 1, v.end(), -twoSum);

			ans += (upper - lower); // 그 값이 몇 개 있는지 다 더해야 함
		}
	}

	std::cout << ans << "\n";

	return 0;
}