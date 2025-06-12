#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> us;
    unordered_map<string, int> um;
    for (auto gem : gems) 
        us.insert(gem);
    
    int left = 0;
    int right = 0;
 
    int minLength = 0x3f3f3f3f;
    vector<int> answer{left, right};
    for (int i = 0; i < gems.size(); i++)
    {
        um[gems[right++]]++;
        
        while (um[gems[left]] > 1)
        {
            um[gems[left]]--;
            left++;
        }
        
        if (um.size() == us.size() && right - left < minLength)
        {
            minLength = right - left;
            answer[0] = left;
            answer[1] = right;
        }
        
    }
    return vector<int>{answer[0] + 1, answer[1]};
}