#include <iostream>
using namespace std;

int board[70][70];
int n;

string ans = "";

bool isSame(int x1, int x2, int y1, int y2)
{
	int first = board[x1][y1];
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (first != board[i][j])
				return false;
		}
	}

	return true;
}


void func(int x1, int x2, int y1, int y2)
{

	if (isSame(x1, x2, y1, y2))
	{
		if (board[x1][y1] == 0)
		{
			ans += "0";
		}
		else
		{
			ans += "1";
		}
		return;
	}

	if (x1 != x2)
		ans += "(";
	int d = (x2 - x1 + 1) / 2;
	for (int i = x1; i <= x2; i += d)
	{
		for (int j = y1; j <= y2; j += d)
		{
			func(i, i + d - 1, j, j + d - 1);
		}
	}
	if (x1 != x2)
		ans += ")";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			board[i][j + 1] = int(str[j]-'0');
		}
	}
	
	func(1, n, 1, n);


	cout << ans << "\n";

	return 0;
}