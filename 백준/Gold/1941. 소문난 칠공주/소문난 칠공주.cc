#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int ans = 0;
const int n = 5;
char board[5][5];
int arr[10];


// 7명 중 이다솜파의 수를 파악
int countS()
{
	int s_num = 0;
	for (int i = 0; i < 7; i++)
	{
		// (q, r)
		int q = arr[i] / 5; 
		int r = arr[i] % 5; 
		if (board[q][r] == 'S') s_num++;
	}

	return s_num;
}

bool isNear()
{
	bool visit[25];
	fill(visit, visit + 25, false);

	queue<int> q;
	q.push(arr[0]);
	visit[arr[0]] = true;

	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		auto cur = q.front(); q.pop();
		for (int nxt : {cur - 5, cur + 5, cur - 1, cur + 1}) // 상, 하, 좌, 우
		{
			if (nxt < 0 || nxt > n * n) continue;
			if (cur % 5 == 4 && nxt % 5 == 0) continue;
			if (cur % 5 == 0 && nxt % 5 == 4) continue;
			if (!binary_search(arr, arr + 7, nxt)) continue;
			if (visit[nxt] == true) continue;
			visit[nxt] = true;
			q.push(nxt);
		}
	}

	if (cnt == 7) return true;
	return false;
}

// 25명 중 7명을 뽑음 (combination)
void func(int cur, int cnt)
{
	if (cnt == 7)
	{
		// 뽑은 7명이 소문난 칠공주가 될 수 있는지 여부 파악
		
		// 1. 이다솜파의 수가 4명 이상인지 여부
		if (countS() < 4) return;
		
		// 2. 서로 인접해 있는지 여부
		if (!isNear()) return;

		// 이다솜파의 수가 4명 이상이고, 뽑은 7명이 서로 인접해 있음
		ans++;
		return;
	}

	for (int i = cur; i < n * n; i++)
	{
		arr[cnt] = i;
		func(i + 1, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			board[i][j] = str[j];
	}

	func(0, 0);

	cout << ans << "\n";

	return 0;
}