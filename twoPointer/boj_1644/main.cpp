#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> prime;
bool tmp[4000001];

// 에라토스테네스의 체를 이용하여 n까지 소수를 판별
void eratos()
{
	if (n <= 1) return;
	fill(tmp + 2, tmp + n + 1, true);

	for (int i = 2; i * i <= n; i++)
	{
		if (tmp[i])
		{
			for (int j = i * i; j <= n; j += i)
				tmp[j] = false;
		}
	}

	for (int i = 1; i <= n; i++)
		if (tmp[i] == true) prime.push_back(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	if (n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	eratos();
	

	int ans = 0;
	// 투 포인터
	int en = 0;
	int sum = prime[0];
	for (int st = 0; st < prime.size(); st++)
	{
		while (en < prime.size() && sum < n)
		{
			++en;
			if (en != prime.size()) sum += prime[en];
		}
		if (en == prime.size()) break;
		if (sum == n) ans++;
		sum -= prime[st];
	}

	cout << ans << "\n";

	return 0;
}