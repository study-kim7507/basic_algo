// 주식이 가장 비싼 날을 찾고, 해당 날 전까지 모든 주식을 사서 비싼 날에 판다
// 이후, 다음으로 주식이 가장 비싼 날을 찾고, 해당 날 전까지 모든 주식을 사서 비싼 날에 판다
// 위의 과정을 반복

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> price;
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			price.push_back(p);
		}


		long long ans = 0;
		int max = price[price.size() - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (price[i] < max) ans += (max - price[i]);
			else if (price[i] >= max) max = price[i];
		}

		cout << ans << "\n";
	}

	return 0;
}