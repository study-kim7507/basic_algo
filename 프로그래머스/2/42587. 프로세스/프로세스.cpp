#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> readyQ;
    queue<int> prioritiesQ;
    
    for (int i = 0; i < priorities.size(); i++)
        readyQ.push({i, priorities[i]});
    
    // 내림차순 정렬
    sort(priorities.rbegin(), priorities.rend());
    for (const auto& prioritie : priorities)
        prioritiesQ.push(prioritie);
    
    int answer = 0;
    while (!readyQ.empty())
    {
        auto front = readyQ.front();
        
        readyQ.pop();
        if (front.second == prioritiesQ.front())
        {    
            prioritiesQ.pop();
            answer++;
            if (front.first == location)
                return answer;
        }
        else
        {
            readyQ.push(front);
        }
    }
    
    return answer;
    
}