// 가방을 최대 용량을 기준으로 오름차순 정렬 -> 2, 10
// 보석을 무게를 기준으로 오름차순 정렬하되, 그 중에서는 가치를 기준으로 내림차순 정렬
// 가방을 오름차순 정렬하고, 매 시점 가방에 넣을 수 있는 보석들을 우선순위 큐에 넣음 (가치 기준 최대 힙)
// 가장 가치가 높은 보석을 하나 빼고, 다음 가방으로 이동
// 위의 과정 반복

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int n, k;
vector<int> bagWeights;
deque<pair<int, int>> jewelry;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        jewelry.push_back({ m, v });
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        bagWeights.push_back(c);
    }

    sort(bagWeights.begin(), bagWeights.end());         // 가방을 최대 용량 기준 오름차순 정렬
    sort(jewelry.begin(), jewelry.end());               // 보석을 무게 기준 오름차순 정렬

    long long totalValue = 0;
    priority_queue<int> pq;                             // 현재 가방에 넣을 수 있는 보석들을 가치 기준으로 최대힙 구성
    for (int i = 0; i < bagWeights.size(); i++)
    {
        int weight = bagWeights[i];
        while (!jewelry.empty() && jewelry.front().first <= weight)
        {
            pq.push(jewelry.front().second);
            jewelry.pop_front();
        }
        
        if (!pq.empty())
        {
            totalValue += pq.top();
            pq.pop();
        }
    }
    
    cout << totalValue << "\n";
    
    return 0;
}