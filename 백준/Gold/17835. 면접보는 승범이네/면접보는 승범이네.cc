// BOJ_17835. 면접보는 승범이네
// 각 도시에서 면접장으로 가는 거리 -> 시간초과
// 모든 면접장에서 동시에 출발해서 각 도시로 이동하는 거리 중 최단거리.
// 기존의 다익스트라의 경우 특정 한 시작정점에서 다른 모든 정점으로의 최단거리를 구하는 것이였다면,
// 해당 문제는 여러 시작 정점에서 다른 모든 정점으로의 최단 거리를 구해. 그 중 가장 큰 값을 반환하는 문제
// 역방향으로 입력을 받고, 여러 면접장에서 동시에 출발. 다른 모든 정점까지의 최단 거리를 구한 뒤,
// 그중 가장 큰 최단 거리를 갖는 정점과 그 거리를 출력하는 문제
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 0x7FFFFFFFFFFFFFFF;

int N, M, K; // 도시(정점) 수, 도로(간선) 수, 면접장 수

struct Edge
{
	int to;
	ll cost;
	bool operator<(const Edge& other) const
	{
		return other.cost < cost;
	}
};

vector<Edge> adj[100001];
vector<int> rooms; // 면접장
ll dist[100001];

void solve()
{
	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < rooms.size(); i++)
		dist[rooms[i]] = 0;
	
	priority_queue<Edge, vector<Edge>> pq;
	for (int i = 0; i < rooms.size(); i++)
		pq.push({ rooms[i], 0});

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
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int U, V;
		ll C;
		cin >> U >> V >> C;
		adj[V].push_back({ U, C });
	}

	for (int i = 0; i < K; i++)
	{
		int room;
		cin >> room;
		rooms.push_back(room);
	}

	solve();
	int maxIdx = -1;
	ll maxValue = -1;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] > maxValue)
		{
			maxIdx = i;
			maxValue = dist[i];
		}
	}

	cout << maxIdx << "\n" << maxValue << "\n";
	return 0;
}

