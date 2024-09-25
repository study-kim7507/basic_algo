// 대칭은 2번, 3번 테트로미노만 유효하다


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[501][501];
int tmp[501][501];

int tetromino[5][9][9] =
{
	{{1, 1, 1, 1}},
	{{1, 1, 0, 0},
	 {1, 1, 0, 0}},
	{{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 1, 0, 0}},
	{{1, 0, 0, 0},
	{1, 1, 0, 0},
	{0, 1, 0, 0}},
	{{1 ,1, 1, 0},
	{ 0,1,0,0 }}
};

pair<int, int> tetrominoSize[5] = 
{	{1, 4},
	{2, 2},
	{3, 2},
	{3, 2},
	{2, 3}
};

void printTetromino()
{
	for (int i = 0; i < 5; i++)
	{
		auto size = tetrominoSize[i];
		for (int r = 0; r < size.first; r++) 
		{
			for (int c = 0; c < size.second; c++)
				cout << tetromino[i][r][c] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
}

void rotation(int num)
{
	// b[x][y] = a[r - 1 - y][x]
	int rotationResult[9][9];
	auto size = tetrominoSize[num];

	for (int r = 0; r < size.second; r++)
		for (int c = 0; c < size.first; c++)
			rotationResult[r][c] = tetromino[num][size.first - 1 - c][r];
	
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (rotationResult[r][c] == 1)
				tetromino[num][r][c] = 1;
			else tetromino[num][r][c] = 0;
		}
	}
	
	swap(tetrominoSize[num].first, tetrominoSize[num].second);
}

void symmetric(int num, int dir)
{
	// 대칭은 2번과 3번만 유효함
	if ((num != 2) && (num != 3)) return;

	int symmetricResult[9][9];
	auto size = tetrominoSize[num];

	if (dir == 0)		// 좌우 대칭
	{
		for (int r = 0; r < size.first; r++)
			for (int c = 0; c < size.second; c++)
				symmetricResult[r][c] = tetromino[num][r][size.second - 1 - c];
		
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				if (symmetricResult[r][c] == 1)
					tetromino[num][r][c] = 1;
				else tetromino[num][r][c] = 0;
			}
		}
	}
	else if (dir == 1)	// 상하 대칭
	{
		for (int r = 0; r < size.first; r++)
			for (int c = 0; c < size.second; c++)
				symmetricResult[r][c] = tetromino[num][size.first - 1 - r][c];

		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				if (symmetricResult[r][c] == 1)
					tetromino[num][r][c] = 1;
				else tetromino[num][r][c] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ans = 0;
	for (int i = 0; i < 5; i++)			// 총 5개의 테트로미노
	{	
		for (int j = 0; j < 4; j++)		// 총 4개의 회전 
		{
			for (int k = 0; k < 2; k++)	// 총 2개의 대칭
			{
				for (int r = 0; r < n; r++)
				{
					for (int c = 0; c < m; c++)
					{
						bool canSum = true;
						int tempAns = 0;
						for (int a = 0; a < tetrominoSize[i].first; a++)
						{
							for (int b = 0; b < tetrominoSize[i].second; b++)
							{
								if (r + a >= n || c + b >= m)
								{
									canSum = false;
									break;
								}
								if (tetromino[i][a][b] == 1)
									tempAns += board[r + a][c + b];
							}
							if (canSum)
							{
								ans = max(ans, tempAns);
							}

						}

					}
				}
				symmetric(i, k);
			}
			if (i != 1) rotation(i);
		}
	}
	

	cout << ans << "\n";

	return 0;
}