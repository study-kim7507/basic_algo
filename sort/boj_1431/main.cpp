#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> serials;

bool cmp(const string& a, const string& b)
{
	// 길이가 다르다면 짧은 것이 먼저온다
	if (a.length() != b.length()) return a.length() < b.length();
	// 길이가 같다면 작은 합을 가지는 것이 먼저 온다
	else
	{
		int aSum = 0;
		int bSum = 0;

		for (int i = 0; i < a.length(); i++)
		{
			aSum = (static_cast<int>(a[i] - '0') >= 0 && static_cast<int>(a[i] - '0') <= 9) ? aSum + static_cast<int>(a[i] - '0') : aSum;
			bSum = (static_cast<int>(b[i] - '0') >= 0 && static_cast<int>(b[i] - '0') <= 9) ? bSum + static_cast<int>(b[i] - '0') : bSum;
		}
		if (aSum != bSum) return aSum < bSum;
	}

	// 1, 2번으로 비교할 수 없다면 사전순으로 비교한다
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i]) continue;
		return static_cast<int>(a[i]) < static_cast<int>(b[i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string num;
		cin >> num;
		serials.push_back(num);
	}

	sort(serials.begin(), serials.end(), cmp);

	for (const string& a : serials)
		cout << a << "\n";

	return 0;
}