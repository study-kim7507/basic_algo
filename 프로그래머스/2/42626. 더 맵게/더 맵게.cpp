#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 매 시점 sort 함수를 이용해 정렬하여 풀 수도 있음.
// 하지만, 해당 경우 O(n * nlgn)의 시간복잡도 예상 -> 시간 초과

// 따라서, priority_queue (min_heap)을 이용하여 heapify O(lg n)의 복잡도
// 최종적으로 O(n * lg n) 예상

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto& e : scoville)
        pq.push(e);
    
    int answer = 0;
    // top (최솟값)이 K 이상일 때까지 반복
    while(pq.top() < K && pq.size() >= 2) // 최대 n번
    {
        answer++;
        
        int first = pq.top(); pq.pop();     // O(1) 
        int second = pq.top(); pq.pop();    // O(1)
        
        int result = first + second * 2;    // O(1)
        pq.push(result);                    // O(lg n)
    }
    
    if (pq.top() < K) return -1;
    
    return answer;
}