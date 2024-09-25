// N x N 크기의 종이
// 1. 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용
// 2. 종이가 모두 같은 수로 되어 있지 않다면 9개로 나누고 1번 반복
#include <iostream>
using namespace std;

int paper[2200][2200]; // 3^7 = 2187
int ans[3]; // -1, 0, 1 종이의 개수
int N;

bool isAllSame(int x1, int x2, int y1, int y2)
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


// 1 9, 1 9
void func(int x1, int x2, int y1, int y2)
{
	// 모두 같으면 종이의 개수를 늘림
	if (isAllSame(x1, x2, y1, y2))
	{
		if (paper[x1][y1] == -1)
			ans[0]++;
		else if (paper[x1][y1] == 0)
			ans[1]++;
		else
			ans[2]++;
		return;
	}

	// 같지 않으면 9등분
	int y_ = (y2 - y1 + 1) / 3;
	int x_ = (x2 - x1 + 1) / 3;
	for (int i = x1; i <= x2; i += x_)
	{
		for (int j = y1; j <= y2; j += y_)
		{
			func(i, i + x_ - 1, j, j + y_ - 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> paper[i][j];
		}
	}


	func(1, N, 1, N);
	for (int a : ans)
	{
		cout << a << "\n";
	}
	return 0;
}