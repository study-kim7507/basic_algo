#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    
    for (int i = 0; i < operations.size(); i++)
    {
        char cmd = operations[i][0];
        string s_num = "";
        for (int j = 2; j < operations[i].size(); j++)
            s_num += operations[i][j];
        int num = stoi(s_num);
        
        if (cmd == 'I') ms.insert(num);
        else if (cmd == 'D' && !ms.empty())
        {
            if (num == 1) ms.erase(--ms.end());
            else if (num == -1) ms.erase(ms.begin());
        }
    }
    
    if (ms.empty()) return vector<int>(2, 0);
    else 
    {
        vector<int> ans;
        ans.push_back(*(--ms.end()));
        ans.push_back(*(ms.begin()));
        return ans;
    }
}