// 이진 탐색 트리의 경우는 왼쪽 자식은 부모보다 작은 값, 오른쪽 자신은 부모보다 큰 값

// 우선 순위 큐 : pop을 할 때 가장 먼저 들어온 원소가 나오는 대신 우선순위가 가장 높은 원소가 나오는 큐
	// 원소의 추가 : O(lg N)
	// 우선순위가 가장 높은 원소의 확인 : O(1)
	// 우선순위가 가장 높은 원소의 제거 : O(N)
// 힙을 이용하여 구현이 이루어짐. 이진 트리의 형태임
	// 최소값, 최대값을 찾는데 용이 
	// 최소힙 - 루트에 가장 최소값, 부모가 자식보다 작은 값
	// 최대값 - 루트에 가장 최대값, 부모가 자식보다 큰 값

	// 삽입
		// 트리의 맨 끝에 값을 삽입하고, 부모와 반복적으로 값을 비교 후 바꿈으로서 루트에 최대, 최소값이 위치하도록 -> O(lg N) : 트리의 높이
	// 탐색 
		// 최대값, 최소값 확인은 단순히 루트의 값만 확인하면 되므로 O(1)
		// 특정 값이 몇 번째인지 확인은 정렬이 되지 않으므로 모든 원소를 확인해보야함 O(n) -> 이진 탐색 트리를 사용하는 것이 적절
	// 삭제
		// 최소값, 최대값 삭제 -> 루트와 맨 마지막 노드의 자리를 바꾸고 마지막 노드에 최소값, 최대값이 위치하도록 한 이후 마지막 노드를 삭제
		// 삭제 이후에 루트에 최대값, 최소값이 위치하지 않으므로 삽입과 동일하게 자리를 바꿔주면서 최대값, 최소값이 루트에 위치하도록


// 배열을 통한 힙 구현
// x번지의 왼쪽 자식 : 2x, 오른쪽 자식 : 2x + 1
// x번지의 부모 : x / 2
#include <iostream>
#include <queue>
using namespace std;

int heap[100005];
int sz = 0;				// 힙에 들어있는 원소의 수

void push(int x)
{
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1)
	{
		int par = idx / 2;
		if (heap[par] <= heap[idx]) break;
		swap(heap[par], heap[idx]);
		idx = par;
	}
}

int top()
{
	return heap[1];
}

void pop()
{
	swap(heap[1], heap[sz--]);
	int idx = 1;

	while (2 * idx <= sz)
	{
		int lc = 2 * idx, rc = 2 * idx + 1;
		int min_child = lc;
		if (rc <= sz && heap[rc] < heap[lc])
			min_child = rc;
		if (heap[idx] <= heap[min_child]) break;
		swap(heap[idx], heap[min_child]);
		idx = min_child;
	}
}

void test()
{
	push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
	cout << top() << '\n'; // 2
	pop(); // {10, 5, 9}
	pop(); // {10, 9}
	cout << top() << '\n'; // 9
	push(5); push(15); // {10, 9, 5, 15}
	cout << top() << '\n'; // 5
	pop(); // {10, 9, 15}
	cout << top() << '\n'; // 9
}

int main()
{
	test();
	return 0;
}
	

void priorityQ_ex()
{
	priority_queue<int> pq; // 최대힙
	priority_queue<int, vector<int>, greater<int>> pq2;		// 최소힙
}