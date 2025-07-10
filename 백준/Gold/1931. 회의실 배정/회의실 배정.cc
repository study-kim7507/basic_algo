#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100001];		// {시작 시각, 끝나는 시각}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		arr[i] = { st, en };
	}
	
	sort(arr, arr + n, cmp);

	int cur = arr[0].second;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first >= cur)
		{
			ans++;
			cur = arr[i].second;
		}
	}

	cout << ans << "\n";
	return 0;
}