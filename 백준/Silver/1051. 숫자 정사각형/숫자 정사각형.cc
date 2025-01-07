// 1051. 숫자 정사각형
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int board[51][51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
			board[i][j] = (int)(input[j] - '0');
	}
		
	int result = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pair<int, int> pos[4];
			// 현재 위치 (좌상단)
			pos[0] = make_pair(i, j);

			for (int k = 1; k < min(n, m); k++)
			{
				// 범위 계산
				if (pos[0].first + k >= n || pos[0].second + k >= m) break;
				
				// 우상단
				pos[1] = make_pair(pos[0].first, pos[0].second + k);

				// 좌하단
				pos[2] = make_pair(pos[0].first + k, pos[0].second);

				// 우하단
				pos[3] = make_pair(pos[0].first + k, pos[0].second + k);
			
				bool isCan = true;
				int num = board[pos[0].first][pos[0].second];
				for (int a = 1; a < 4; a++)
				{
					// 하나라도 다른 경우
					if (num != board[pos[a].first][pos[a].second])
					{
						isCan = false;
						break;
					}
				}
				if (isCan) result = max(result, k + 1);
			}
		}
	}
	
	if (result == 1) cout << 1 << "\n";
	else cout << pow(result, 2) << "\n";

	return 0;
}