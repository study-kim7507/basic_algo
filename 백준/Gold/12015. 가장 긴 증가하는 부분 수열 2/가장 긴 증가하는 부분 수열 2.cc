// BOJ 12015. 가장 긴 증가하는 부분 수열 2
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

	vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		auto it = lower_bound(lis.begin(), lis.end(), input);
		if (it == lis.end()) lis.push_back(input);
		else *it = input;
	}

	std::cout << lis.size() << "\n";

	return 0;
}