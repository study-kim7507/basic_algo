// 1018. 체스판 다시 칠하기
#include <iostream>
#include <algorithm>
using namespace std;

string comp[2] = { "WBWBWBWB", "BWBWBWBW" };

int n, m;
char board[51][51];
string cur[8];

int result = 10000;

bool getBoard(int x, int y)
{
	if (x + 7 > n || y + 7 > m) return false;

	for (int i = 0; i < 8; i++)
		cur[i] = "";

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cur[i] += board[x + i][y + j];

	return true;
}

int count()
{
	int cnt1 = 0;
	for (int i = 0; i < 8; i++)
	{
		string curComp;
		if (i % 2 == 0) curComp = comp[0];
		else curComp = comp[1];

		for (int j = 0; j < 8; j++)
		{
			if (cur[i][j] != curComp[j]) cnt1++;
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < 8; i++)
	{
		string curComp;
		if (i % 2 == 0) curComp = comp[1];
		else curComp = comp[0];

		for (int j = 0; j < 8; j++)
		{
			if (cur[i][j] != curComp[j]) cnt2++;
		}
	}

	return min(cnt1, cnt2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!getBoard(i, j)) continue;
			result = min(result, count());
		}
	}

	cout << result << "\n";

	return 0;
}
