// BOJ 2352. 반도체 설계
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
		int num;
		cin >> num;

		auto lb = lower_bound(lis.begin(), lis.end(), num);
		if (lb == lis.end())
			lis.push_back(num);
		else *lb = num;
	}
	std::cout << lis.size() << "\n";
	return 0;
}