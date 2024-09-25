// 기존 구현은 서로 다른 두 우주를 비교하면서 좌표 압축을 진행 -> O(m^2nlgn) -> 대략 최대 10억
// 좌표 압축을 먼저 진행하고, 그들을 비교 -> 좌표 압축에 걸리는 시간 복잡도 : O(mnlgn) + 서로 다른 두 우주를 비교 : O(m^2n)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int arr[101][10001];
int tmp[101][10001];
int compress[101][10001];

vector<int> combi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}
		
	for (int i = 0; i < m; i++)
		sort(tmp[i], tmp[i] + n);

	
	// O(mnlgN)
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			compress[i][j] = lower_bound(tmp[i], tmp[i] + n, arr[i][j]) - tmp[i];

	// O(m^2n)
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			bool isSame = true;
			for (int k = 0; k < n; k++)
			{
				if (compress[i][k] != compress[j][k])
				{
					isSame = false;
					break;
				}
			}
			if (isSame) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}