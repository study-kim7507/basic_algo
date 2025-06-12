#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    vector<long long> p1, p2;
    for (int i = 0; i < sequence.size(); i++)
    {
        if (i % 2 == 0) 
        {
            p1.push_back(sequence[i]);
            p2.push_back(sequence[i] * -1);
        }
        else 
        {
            p1.push_back(sequence[i] * -1);
            p2.push_back(sequence[i]);
        }
    }
    
    vector<long long> dp1, dp2;
    dp1.push_back(p1[0]);
    dp2.push_back(p2[0]);
    
    for (int i = 1; i < sequence.size(); i++)
    {
        dp1.push_back(max(dp1[i-1] + p1[i], p1[i]));
        dp2.push_back(max(dp2[i-1] + p2[i], p2[i]));
    }
    
    return max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));
}