// 동시에 빠져도 실패.

#include <iostream>
#include <vector>
using namespace std;

int n, m;
char board[15][15];

pair<int, int> r;					// 현재 빨간 구슬의 위치
pair<int, int> b;					// 현재 파란 구슬의 위치
pair<int, int> goal;				// 출구의 위치
vector<char> holeIn;
pair<int, int> tiltDir[4] =
{
	{0, -1},			// 왼쪽으로 기울이기
	{0, 1},				// 오른쪽으로 기울이기
	{-1, 0},			// 위쪽으로 기울이기
	{1, 0},				// 아래쪽으로 기울이기
};

void printBoard()
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
			cout << board[r][c];
		cout << "\n";
	}
	cout << "\n";
}

void tilt(const int& dir)
{
	// 벽을 만날 때까지 기울이기
	while (board[r.first + tiltDir[dir].first][r.second + tiltDir[dir].second] == '.' ||
		board[r.first + tiltDir[dir].first][r.second + tiltDir[dir].second] == 'O' || 
		board[b.first + tiltDir[dir].first][b.second + tiltDir[dir].second] == '.' || 
		board[b.first + tiltDir[dir].first][b.second + tiltDir[dir].second] == 'O')
	{
		if (board[r.first + tiltDir[dir].first][r.second + tiltDir[dir].second] == '.')
		{
			if (board[r.first][r.second] != 'O')
				board[r.first][r.second] = '.';
			r.first += tiltDir[dir].first;
			r.second += tiltDir[dir].second;
			board[r.first][r.second] = 'R';
		}
		else if (board[r.first + tiltDir[dir].first][r.second + tiltDir[dir].second] == 'O')
		{
			board[r.first][r.second] = '.';
			r.first += tiltDir[dir].first;
			r.second += tiltDir[dir].second;
			holeIn.push_back('R');
		}
		if (board[b.first + tiltDir[dir].first][b.second + tiltDir[dir].second] == '.')
		{
			if (board[b.first][b.second] != 'O')
				board[b.first][b.second] = '.';
			b.first += tiltDir[dir].first;
			b.second += tiltDir[dir].second;
			board[b.first][b.second] = 'B';
		}
		else if (board[b.first + tiltDir[dir].first][b.second + tiltDir[dir].second] == 'O')
		{
			board[b.first][b.second] = '.';
			b.first += tiltDir[dir].first;
			b.second += tiltDir[dir].second;
			holeIn.push_back('B');
		}
	}
}

int ans = 987654321;
void func(int cnt)
{
	// 횟수가 10번을 넘었거나
	if (cnt > 10) return;
	// 출구에 구슬이 도착했을 경우
	if (holeIn.size() == 1 && holeIn[0] == 'R')
	{
		ans = min(ans, cnt);
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		vector<char> tmpHoleIn = holeIn;
		pair<int, int> tmpR, tmpB;
		char tmp[15][15];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = board[i][j];
		tmpR = r; tmpB = b;
		
		tilt(dir);

		func(cnt + 1);
		
		holeIn = tmpHoleIn;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] = tmp[i][j];
		r = tmpR; b = tmpB;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (row == 0 || row == n - 1) board[row][col] = '#';
			if (col == 0 || col == m - 1) board[row][col] = '#';
			cin >> board[row][col];
			if (board[row][col] == 'R') r = { row, col };
			else if (board[row][col] == 'B') b = { row, col };
			else if (board[row][col] == 'O') goal = {row, col};
		}
	}
	
	/*printBoard();
	tilt(1);
	printBoard();
	for (auto c : holeIn)
		cout << c << " ";
	cout << "\n";*/

	func(0);
	if (ans == 987654321) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}