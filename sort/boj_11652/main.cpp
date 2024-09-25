#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<ll> inputs;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll num;
		cin >> num;
		inputs.push_back(num);
	}
	sort(inputs.begin(), inputs.end());

	
	int cnt = 0;
	int curCnt = 1;
	ll ans = inputs[0];
	ll cur = inputs[0];
	for (int i = 1; i < n; i++)
	{
		if (cur == inputs[i]) curCnt++;
		if (cur != inputs[i])
		{
			if (cnt < curCnt)
			{
				cnt = curCnt;
				ans = cur;
			}
			cur = inputs[i];
			curCnt = 1;
		}
	}
	if (cnt < curCnt)
		ans = cur;

	cout << ans << "\n";
	return 0;
}