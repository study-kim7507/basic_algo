// BOJ_18870. 좌표 압축
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
	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
		v2[i] = v1[i];
	}
		

	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (auto e : v1)
		std::cout << lower_bound(v2.begin(), v2.end(), e) - v2.begin() << " ";

	return 0;
}