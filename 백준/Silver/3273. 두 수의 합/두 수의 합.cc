// BOJ_3273. 두 수의 합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cnt[2000001];
vector<int> nums;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
		cnt[a] = true;
	}
	cin >> x;

	int result = 0;
	for (auto num : nums)
	{
		if (num >= x) continue;
		if (x - num == num) continue;
		if (!cnt[x - num]) continue;

		result++;
	}

	std::cout << result / 2 << "\n";

	return 0;
}