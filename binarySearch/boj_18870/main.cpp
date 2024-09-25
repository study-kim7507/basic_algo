#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long x[1000001];
vector<long long> tmp, uni;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		tmp.push_back(x[i]);
	}
		
	// 정렬
	sort(tmp.begin(), tmp.end());

	// 중복 제거
	for (int i = 0; i < n - 1; i++)
	{
		if (tmp[i] != tmp[i + 1])
			uni.push_back(tmp[i]);
	}

	for (int i = 0; i < n; i++)
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
	cout << "\n";

	return 0;
}