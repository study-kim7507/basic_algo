// 다시풀기

// min heap (priority queue)
// value, index 를 같이 저장
// heap의 root에는 value가 가장 작은 것이 저장되어 있음.
// 매 시점 value가 가장 작은 것이 최솟값이 되는데, 이 때 index가 유효하지 않다면 제거

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first > b.first;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	vector<int> result;
	// <value, index>
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < N; i++)
	{
		pq.push({ arr[i], i });
		int pos = pq.top().second;
		while (pos <= i - L)
		{
			pq.pop();
			pos = pq.top().second;
		}
		cout << pq.top().first << " ";
	}

	return 0;
}
