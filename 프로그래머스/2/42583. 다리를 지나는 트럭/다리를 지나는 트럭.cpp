#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> remainTrucks;    // 남은 대기 트럭
    queue<pair<int, int>> onBridgeTrucks;  // {현재 다리 위에 있는 트럭, 다리 위에 올라온 시간}
    
    int currentWeight = 0;      // 현재 다리 위에 있는 트럭의 총 무게
    int time = 0;               // 경과 시간
    
    
    for (auto& e : truck_weights)
        remainTrucks.push(e);
    
    while(!remainTrucks.empty() || !onBridgeTrucks.empty())
    {
        time++;
        
        // 다리 위에 트럭이 있다면 현재 시간과 트럭이 다리에 올라온 시간을 비교
        // 다 건넜다고 판단되면, 다리에서 제거
        if (!onBridgeTrucks.empty())
        {
            int enterTime = onBridgeTrucks.front().second;
            if (time - enterTime >= bridge_length)
            {
                currentWeight -= onBridgeTrucks.front().first;
                onBridgeTrucks.pop();
            }
        }
        
        // 남은 대기 트럭 있다면, 다리 위의 트럭 올라갈 수 있는지 판단하여 올림
        if (!remainTrucks.empty())
        {
            // 개수 및 무게 판단
            if (onBridgeTrucks.size() < bridge_length && 
               currentWeight + remainTrucks.front() <= weight)
            {
                currentWeight += remainTrucks.front();
                onBridgeTrucks.push({remainTrucks.front(), time});
                remainTrucks.pop();
            }
        }
    }
    
    return time;
}