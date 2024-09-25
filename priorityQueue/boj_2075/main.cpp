// 초기 풀이 : 모든 수를 최대 힙에 저장하고, n - 1번째까지 뽑아낸 뒤 n번째 수를 출력
// 메모리 제한 12MB -> 모든 수를 힙에 저장하게 되면 최대 1500개이므로 메모리 초과


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> min_heap;		// 최소 힙

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	


	cin >> n;
	for (int i = 0; i < n * n; i++)
	{
		int num;
		cin >> num;
		
		if (min_heap.size() < n)
			min_heap.push(num);
		else if (min_heap.top() < num)
		{
			min_heap.pop();
			min_heap.push(num);
		}
	}

	cout << min_heap.top() << "\n";
	

	return 0;
}