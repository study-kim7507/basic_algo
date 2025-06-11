// BOJ_2096. 내려가기
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int board[100001][3];
int dpMax[3];
int dpMin[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	dpMax[0] = dpMin[0] = board[0][0];
	dpMax[1] = dpMin[1] = board[0][1];
	dpMax[2] = dpMin[2] = board[0][2];

	for (int i = 1; i < n; i++)
	{
		int maxTemp[3], minTemp[3];

		maxTemp[0] = max(dpMax[0], dpMax[1]) + board[i][0];
		maxTemp[1] = max({ dpMax[0], dpMax[1], dpMax[2] }) + board[i][1];
		maxTemp[2] = max(dpMax[1], dpMax[2]) + board[i][2];

		minTemp[0] = min(dpMin[0], dpMin[1]) + board[i][0];
		minTemp[1] = min({ dpMin[0], dpMin[1], dpMin[2] }) + board[i][1];
		minTemp[2] = min(dpMin[1], dpMin[2]) + board[i][2];

		dpMax[0] = maxTemp[0];
		dpMax[1] = maxTemp[1];
		dpMax[2] = maxTemp[2];

		dpMin[0] = minTemp[0];
		dpMin[1] = minTemp[1];
		dpMin[2] = minTemp[2];
	}			   

	std::cout << max({ dpMax[0], dpMax[1], dpMax[2] }) << " ";
	std::cout << min({ dpMin[0], dpMin[1], dpMin[2] }) << " ";


	return 0;
}