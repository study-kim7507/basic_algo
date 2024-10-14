// BOJ_1261. 알고스팟.
// (1, 1)에서 (N,M)으로 이동하는데 부셔야하는 벽의 개수
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;

int N, M;
int maze[101][101];

struct Edge
{
	int to;
	int cost;
	bool operator<(const Edge& other) const
	{
		return other.cost < cost;
	}
};

vector<Edge> adj[10001];
int dist[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N; // 가로, 세로
	// 미로 입력 받기
	for (int i = 1; i <= N; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= M; j++)
			maze[i][j] = (int)(input[j - 1] - '0');
	}
	int nodeNum = 1;
	int temp[5] = { 0, -1, -M, 1, +M };
	int dx[5] = { 0, -1, 0, 1, 0 };
	int dy[5] = { 0, 0, -1, 0, 1 };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int dir = 1; dir <= 4; dir++)
			{
				int nxtNodeNum = nodeNum + temp[dir];
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (nxtNodeNum <= 0 || nxtNodeNum > M * N) continue;
				if (nx <= 0 || nx > M || ny <= 0 || ny > N) continue;
				adj[nodeNum].push_back({ nxtNodeNum, maze[ny][nx] });
			}
			nodeNum++;
		}
	}

	fill(dist, dist + (N * M) + 1, INF);
	dist[1] = 0;
	priority_queue<Edge, vector<Edge>> pq;
	pq.push({ 1, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top(); pq.pop();
		if (dist[curr.to] < curr.cost) continue;
		for (auto node : adj[curr.to])
		{
			if (dist[node.to] > curr.cost + node.cost)
			{
				dist[node.to] = curr.cost + node.cost;
				pq.push({ node.to, dist[node.to] });
			}
		}
	}

	cout << dist[N * M] << "\n";

	return 0;
}