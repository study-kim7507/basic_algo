// BOJ_2295. 세 수의 합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	
	vector<int> twoSums;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			twoSums.push_back(nums[i] + nums[j]);
	sort(twoSums.begin(), twoSums.end());

	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (binary_search(twoSums.begin(), twoSums.end(), nums[i] - nums[j]))
			{
				std::cout << nums[i] << "\n";
				return 0;
			}
		}
	}

	return 0;
}