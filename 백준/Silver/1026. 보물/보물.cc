// BOJ_1026. 보물
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	vector<int> a;
	vector<int> b;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		b.push_back(num);
	}


	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];

	std::cout << ans << "\n";

	return 0;
}