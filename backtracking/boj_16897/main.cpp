#include <iostream>
using namespace std;

struct egg
{
	int def;
	int weight;
	bool isbroken;
};

int n;
egg input[10];
int ans = -987654321;

void func(int cur)
{
	if (cur == n)
	{
		int tempCnt = 0;
		// 부셔진 계란 개수 카운트
		for (int i = 0; i < n; i++)
		{
			if (input[i].isbroken == true)
				tempCnt++;
		}
		if (ans < tempCnt) ans = tempCnt;
		return;
	}

	if (input[cur].isbroken == true)
	{
		func(cur + 1);
		return;
	}

	bool isAllBreak = true;
	for (int i = 0; i < n; i++)
	{
		if (i == cur) continue;
		if (input[i].isbroken == true) continue;

		isAllBreak = false;

		input[cur].def -= input[i].weight;
		input[i].def -= input[cur].weight;
		if (input[cur].def <= 0) input[cur].isbroken = true;
		if (input[i].def <= 0) input[i].isbroken = true;

		func(cur + 1);

		input[cur].def += input[i].weight;
		input[i].def += input[cur].weight;
		if (input[cur].def > 0) input[cur].isbroken = false;
		if (input[i].def > 0) input[i].isbroken = false;
	}

	// 손에 든 계란 이외의 모든 계란이 부셔져 있는 경우.
	if (isAllBreak && (cur != n))
	{
		func(cur + 1);
		return;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int def;
		int weight;
		cin >> def >> weight;
		input[i] = egg{ def, weight, false };
	}

	func(0);

	cout << ans << "\n";

	return 0;
}