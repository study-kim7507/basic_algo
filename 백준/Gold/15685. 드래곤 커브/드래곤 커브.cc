// BOJ 15685. 드래곤 커브
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int board[101][101];

// 다음 세대 : 이전 세대 방향 + (이전 세대 방향 역순 + 1)
void generateCurve(int curGene, int targetGene, vector<int>& curve)
{
	if (curGene == targetGene)
		return;

	vector<int> temp(curve.rbegin(), curve.rend());
	for (auto dir : temp)
	{
		dir++;
		if (dir >= 4) dir = 0;
		curve.push_back(dir);
	}
		
	
	generateCurve(curGene + 1, targetGene, curve);
}

void draw(int x, int y, vector<int>& curve)
{
	for (int i = 0; i < curve.size(); i++)
	{
		int curGene = curve[i];

		board[x][y] = 1;
		
		// x좌표가 증가하는 방향
		if (curGene == 0) y++;
		else if (curGene == 1) x--;
		else if (curGene == 2) y--;
		else if (curGene == 3) x++;
	}
	board[x][y] = 1;
}

int count()
{
	int ret = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			bool can = true;
			if (board[i][j] == 0) can = false;
			if (board[i + 1][j] == 0) can = false;
			if (board[i][j + 1] == 0) can = false;
			if (board[i + 1][j + 1] == 0) can = false;

			if (can) ret++;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// x, y 시작지점
		// d 시작 방향
		// g 세대
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<int> curve;
		curve.push_back(d);
		generateCurve(0, g, curve);
		draw(y, x, curve);
	}

	std::cout << count() << "\n";

	return 0;
}