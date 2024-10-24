// 우선순위 큐를 이용하여 중앙값 찾기
// 최대 힙, 최소 힙 두 개의 힙을 이용


// 1. 최대힙의 크기는 최소힙의 크기와 같거나 하나 큼
// 2. 최대힙의 top은 최소힙의 top보다 작거나 같음 -> 만족하지 못할 경우, 두 힙의 top을 스왑
// 3. 매 시점 최대힙의 top이 중앙값이 된다.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (max_heap.size() == 0 || max_heap.size() <= min_heap.size())
			max_heap.push(input);
		else
			min_heap.push(input);

		if ((!max_heap.empty() && !min_heap.empty()) && max_heap.top() > min_heap.top())
		{
			int maxHeapTop = max_heap.top();
			max_heap.pop();
			int minHeapTop = min_heap.top();
			min_heap.pop();
			max_heap.push(minHeapTop);
			min_heap.push(maxHeapTop);
		}

		cout << max_heap.top() << "\n";
	}

	return 0;
}