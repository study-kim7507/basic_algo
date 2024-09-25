// 두 용액의 특성값의 합이 0에 가까운 두 용액의 특성값을 출력
// 현재 선택된 용액의 특성값의 반대부호의 특성값을 갖는 용액이 배열에 존재하는지 이진탐색
	// 존재한다면 해당 값들의 특성값의 합이 0이므로 답
	// 존재하지 않다면, 근처의 특성값의 합

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

typedef long long ll;

int n;
ll arr[100001];

ll bs(int st, int en, ll target)
{
	if (target == arr[st]) return st;
	if (st >= en) return st;
	int mid = (st + en + 1) / 2;
	if (target >= arr[mid]) return bs(mid, en, target);
	else return bs(st, mid - 1, target);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll sum = numeric_limits<ll>::max();
	pair<ll, ll> result;
	for (int i = 0; i < n - 1; i++)
	{
		ll target = -arr[i];
		int bsResultIdx = bs(i + 1, n - 1, target);
		for (const int& idx : { bsResultIdx - 1, bsResultIdx, bsResultIdx + 1 })
		{
			if (idx == i || idx < 0 || idx >= n) continue;
			ll bsResultVal = arr[idx];
			ll tmpSum = arr[i] + bsResultVal;
			if (abs(tmpSum) <= sum)
			{
				sum = abs(tmpSum);
				result = { arr[i], bsResultVal };
			}
		}
	}

	cout << result.first + result.second << "\n";
	return 0;
}