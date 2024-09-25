#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[26][26];
bool visit[26][26];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = int(str[j] - '0');
		}
	}

	vector<int> result;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1 && !visit[i][j])
			{
				int count = 0;
				queue<pair<int, int>> q;
				q.push({ i, j });
				visit[i][j] = true;
				while (!q.empty())
				{
					count++;
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (board[nx][ny] != 1 || visit[nx][ny]) continue;
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
				result.push_back(count);
			}	
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int a : result)
	{
		cout << a << "\n";
	}
	return 0;
}