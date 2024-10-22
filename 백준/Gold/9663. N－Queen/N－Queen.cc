// 퀸은 상하좌우, 대각 모두 공격 가능
// NxN 체스판 위에 퀸 N개를 서로 공격할 수 없게
// 행마다 하나의 퀸을 배치하면서 내려오게 설계
// 재귀 -> 백트래킹 : 가능한 모든 경우의 수를 판단

#include <iostream>
using namespace std;

bool isused1[15]; // 각 열에 퀸이 있는지
bool isused2[30]; // 좌상 - 우하 대각선(/)
bool isused3[30]; // 우상 - 좌하 대각선(\)

int n;
int ans = 0;

void func(int k)
{
	if (k == n)
	{
		ans++;
		return;
	}
	
	for (int j = 0; j < n; j++)
	{
		if (isused1[j] || isused2[k + j] || isused3[k - j + n - 1])
			continue;

		isused1[j] = true;
		isused2[k + j] = true;
		isused3[k - j + n - 1] = true;

		func(k + 1);

		isused1[j] = false;
		isused2[k + j] = false;
		isused3[k - j + n - 1] = false;

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	func(0);
	
	cout << ans << "\n";

	return 0;
}