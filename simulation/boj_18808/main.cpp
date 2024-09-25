// 2차원 배열 회전 B[x][y] = A[r-1-y][x]

#include <iostream>
#include <vector>
using namespace std;

int n, m;			// 노트북의 가로와 세로 (n -> y, m -> x)
int k;				// 스티커의 개수
int r, c;			// 스티커가 인쇄된 모눈 종이의 크기 (r- > x, c -> y)

int notebook[40][40];
int sticker[100][15][15];				// 스티커가 인쇄된 모눈 종이에 인쇄되었는지
pair<int, int> stickerInfo[100];		// 각 스티커가 어떤 크기의 모눈 종이에 인쇄되었는지

int ans = 0;

void rotation(int stickerNum)
{
	int tempSticker[15][15];

	int r = stickerInfo[stickerNum].first;
	int c = stickerInfo[stickerNum].second;
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			tempSticker[i][j] = sticker[stickerNum][r - 1 - j][i];
			sticker[stickerNum][r - 1 - j][i] = 0;
		}
	}

	int temp = r;
	stickerInfo[stickerNum].first = c;
	stickerInfo[stickerNum].second = temp;

	r = stickerInfo[stickerNum].first;
	c = stickerInfo[stickerNum].second;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			sticker[stickerNum][i][j] = tempSticker[i][j];
		}
	}
}

bool canAttach(int curX, int curY, int stickerNum)
{
	int r = stickerInfo[stickerNum].first;
	int c = stickerInfo[stickerNum].second;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (notebook[curX + i][curY + j] == 1 &&
				sticker[stickerNum][i][j] == 1)
				return false;
			if (curX + i >= n || curY + j >= m) return false;
		}
	}

	return true;
}

void attachSticker(int curX, int curY, int stickerNum)
{
	int r = stickerInfo[stickerNum].first;
	int c = stickerInfo[stickerNum].second;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (notebook[curX + i][curY + j] == 1) continue;
			notebook[curX + i][curY + j] = sticker[stickerNum][i][j];
		}
	}
}
void func(int stickerNum)
{
	if (ans != 0) return;
	if (stickerNum == k && ans == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (notebook[i][j] == 1) ans++;
		}
		return;
	}

	int x = stickerInfo[stickerNum].first;
	int y = stickerInfo[stickerNum].second;
	int curSticker[15][15];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			curSticker[i][j] = sticker[stickerNum][i][j];
	}

	bool isAttached = false;
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!canAttach(i, j, stickerNum)) continue;

				// Attach sticker to notebook
				attachSticker(i, j, stickerNum);
				isAttached = true;

				func(stickerNum + 1);
				return;
			}
		}
		if (!isAttached)
			rotation(stickerNum);
	}

	if (stickerNum != k)
		func(stickerNum + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;		// 노트북의 가로, 세로, 스티커의 개수

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		stickerInfo[i] = { r, c };
		for (int a = 0; a < r; a++)
		{
			for (int b = 0; b < c; b++)
			{
				cin >> sticker[i][a][b];
			}				
		}
	}

	/* for debugging */
	// rotation(1);
	// rotation(1);
	// rotation(1);
	// rotation(1);

	func(0);

	cout << ans << "\n";
	return 0;
}