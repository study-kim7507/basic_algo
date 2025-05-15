#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {    
    unordered_map<int, int> m;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    for (int i = 0; i < operations.size(); i++)
    {
        char cmd = operations[i][0];
        string s_num = "";
        for (int j = 2; j < operations[i].size(); j++)
            s_num += operations[i][j];
        int num = stoi(s_num);
        
        // 삽입
        if (cmd == 'I')
        {
            m[num]++;
            maxHeap.push(num);
            minHeap.push(num);
        }
        // 삭제
        else if (cmd == 'D')
        {
            // 최댓값 삭제 (maxHeap)
            if (num == 1)
            {
                while (!maxHeap.empty())
                {
                    int top = maxHeap.top(); maxHeap.pop();
                    if (m[top] != 0)
                    {
                        m[top]--;
                        break;
                    }
                }
                    
            }
            // 최솟값 삭제 (minHeap)
            else if (num == -1)
            {
                while (!minHeap.empty())
                {
                    int top = minHeap.top(); minHeap.pop();
                    if (m[top] != 0)
                    {
                        m[top]--;
                        break;
                    }
                }
            }
        }
    }
    
    while(!maxHeap.empty() && m[maxHeap.top()] == 0)
        maxHeap.pop();
    
    while(!minHeap.empty() && m[minHeap.top()] == 0)
        minHeap.pop();
    
    vector<int> ans;
    if (maxHeap.empty()) return vector<int>(2, 0);
    else 
    {
        ans.push_back(maxHeap.top());
        ans.push_back(minHeap.top());
    }
    return ans;
}