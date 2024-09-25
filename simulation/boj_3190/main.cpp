#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n;
int board[110][110];
int k;
int l;

vector<pair<int, char>> inputs;

pair<int, int> moveForward[4] =
{
	{-1, 0},			// 위
	{0, 1},				// 오른쪽
	{1, 0},				// 아래
	{0, -1},			// 왼쪽
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 보드의 크기를 입력 받고, 벽을 생성
	cin >> n;
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == 0 || i == n + 1) board[i][j] = 1;
			if (j == 0 || j == n + 1) board[i][j] = 1;
		}
	}

	// 사과의 개수를 입력 받고, 보드에 사과를 생성
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = -1;		
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		inputs.push_back({ x, c });
	}

	deque<pair<int, int>> snake;
	snake.push_back({ 1, 1 });			// 뱀의 시작
	board[1][1] = 2;					// 현재 뱀이 존재하는 칸을 기록
	int curDir = 1;						// 초기에는 오른쪽을 바라보며 이동

	int sec = 0;
	int idx = 0;
	while (true)
	{
		if (idx < inputs.size() && inputs[idx].first == sec)
		{
			if (inputs[idx].second == 'L') curDir = curDir - 1 < 0 ? 3 : curDir - 1;
			else if (inputs[idx].second == 'D') curDir = curDir + 1 > 3 ? 0 : curDir + 1;
			idx++;
		}
		auto head = snake.front();
		head.first += moveForward[curDir].first;
		head.second += moveForward[curDir].second;

		// 이동한 칸에 사과가 있다면, 사과는 사라짐
		if (board[head.first][head.second] == -1) board[head.first][head.second] = 0;
		// 이동한 칸에 사과가 없다면, 꼬리 칸의 자리는 비워준다
		else if (board[head.first][head.second] == 0)
		{
			auto tail = snake.back(); snake.pop_back();
			board[tail.first][tail.second] = 0;
		}
		// 벽이나, 뱀 자기자신과 부딪히면 게임 종료
		else if (board[head.first][head.second] == 1 || board[head.first][head.second] == 2) break;

		// 뱀의 머리를 이동시키고 보드에 표기
		snake.push_front({ head.first, head.second });
		board[head.first][head.second] = 2;
		sec++;
	}

	cout << sec + 1 << "\n";
	return 0;
}