// BOJ_17140. 이차원 배열과 연산
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
int curRSize = 3, curCSize = 3;
int board[101][101];

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second > b.second) return a.second > b.second;
		else if (a.second == b.second) return a.first > b.first;
		return false;
	}
};


void cal()
{
	// {수, 횟수}
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> rp[101];
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> cp[101];

	int tempRowSize = 0;
	for (int i = 0; i < curCSize; i++)
	{
		map<int, int> tempM;
		for (int j = 0; j < curRSize; j++)
		{
			if (board[i][j] != 0)
				tempM[board[i][j]]++;
		}
			

		for (auto it = tempM.begin(); it != tempM.end(); it++)
			rp[i].push({ (*it).first, (*it).second });

		tempRowSize = max(tempRowSize, int(rp[i].size()) * 2);
	}

	int tempColSize = 0;
	for (int i = 0; i < curRSize; i++)
	{
		map<int, int> tempC;
		for (int j = 0; j < curCSize; j++)
		{
			if (board[j][i] != 0)
				tempC[board[j][i]]++;
		}
			

		for (auto it = tempC.begin(); it != tempC.end(); it++)
			cp[i].push({ (*it).first, (*it).second });
		tempColSize = max(tempColSize, int(cp[i].size()) * 2);
	}

	if (curRSize <= curCSize)
	{
		for (int i = 0; i < curCSize; i++)
		{
			for (int j = 0; j <= tempRowSize && j <= 100; j += 2)
			{
				if (!rp[i].empty())
				{
					auto cur = rp[i].top(); rp[i].pop();
					board[i][j] = cur.first;
					board[i][j + 1] = cur.second;
				}
				else board[i][j] = board[i][j + 1] = 0;
			}
		}
		curRSize = tempRowSize;
	}
	else
	{
		for (int i = 0; i < curRSize; i++)
		{
			for (int j = 0; j < tempColSize && j <= 100; j += 2)
			{
				if (!cp[i].empty())
				{
					auto cur = cp[i].top(); cp[i].pop();
					board[j][i] = cur.first;
					board[j + 1][i] = cur.second;
				}
				else board[j][i] = board[j + 1][i] = 0;
			}
		}
		curCSize = tempColSize;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	int time = 0;
	while (true)
	{
		if (board[r - 1][c - 1] == k || time > 100) break;

		cal();
		time++;
	}

	if (time <= 100) std::cout << time << "\n";
	else std::cout << -1 << "\n";
	return 0;
}