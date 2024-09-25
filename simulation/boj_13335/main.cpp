#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;					// 다리를 건너는 트럭의 수
int truck[1001];		// 다리를 건너는 트럭의 무게

int w, l;				// 다리의 길이, 다리의 최대 하중
queue<int> bridge;		

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> truck[i];

	for (int i = 0; i < w; i++)
		bridge.push(0);

	int sum = 0;
	int cnt = 0;
	int ans = 0;
	int comp = 0;
	int cur = 0;
	while (comp != n)
	{
		sum -= bridge.front();
		if (bridge.front() != 0) comp++;
		bridge.pop();

		if (sum + truck[cur] <= l && bridge.size() < w)
		{
			sum += truck[cur];
			bridge.push(truck[cur++]);
		}

		else bridge.push(0);
		ans++;
	}

	cout << ans << "\n";
	return 0;
}