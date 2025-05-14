#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    stack<pair<int, int>> s;
    vector<int> answer(prices.size(), 0);
    
    for (int i = 0; i < prices.size(); i++)
    {
        if (s.empty()) s.push({prices[i], i});
        else
        {
            while (!s.empty() && s.top().first > prices[i])
            {
                answer[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({prices[i], i});
        }
    }
    
    while (!s.empty())
    {
        auto top = s.top(); s.pop();
        answer[top.second] = prices.size() - 1 - top.second;
    }
    
    return answer;
}