#include <iostream>
using namespace std;

int paper[130][130];
int n;
int ans[2]; // 0, 1

bool isSame(int x1, int x2, int y1, int y2)
{
	int first = paper[x1][y1];
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (first != paper[i][j])
				return false;
		}
	}

	return true;
}

void func(int x1, int x2, int y1, int y2)
{
	// 모두 같은 색으로 칠해져 있는 경우
	if (isSame(x1, x2, y1, y2))
	{
		ans[paper[x1][y1]]++;
		return;
	}

	int d = (x2 - x1 + 1) / 2;
	for (int i = x1; i <= x2; i += d)
	{
		for (int j = y1; j <= y2; j += d)
		{
			func(i, i + d - 1, j, j + d - 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];
	}

	func(1, n, 1, n);

	for (int i : ans)
	{
		cout << i << "\n";
	}

	return 0;
}