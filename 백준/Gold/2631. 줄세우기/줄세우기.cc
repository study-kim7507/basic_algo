// BOJ_2631. 줄세우기
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
	vector<int> num(n, 0);
	vector<int> dp;

	for (int i = 0; i < n; i++)
		cin >> num[i];
	dp.push_back(num[0]);

	for (int i = 1; i < n; i++)
	{
		if (dp.back() < num[i]) dp.push_back(num[i]);
		else
		{
			auto it = lower_bound(dp.begin(), dp.end(), num[i]);
			*it = num[i];
		}
	}

	std::cout << n - dp.size() << "\n";
	return 0;
}