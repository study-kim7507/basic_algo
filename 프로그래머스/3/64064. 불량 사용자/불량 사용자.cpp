#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>


using namespace std;

bool vis[8];
set<set<string>> list;

void solve(int idx, set<string> curList, vector<string> user_id, vector<string> banned_id)
{
    if (idx == banned_id.size())
    {   
        list.insert(curList);
        return;
    }
    
    string curBannedId = banned_id[idx];
    for (int i = 0; i < user_id.size(); i++)
    {
        string curUserId = user_id[i];
        if (curBannedId.size() != curUserId.size()) continue;
        if (vis[i]) continue;
        
        bool can = true;
        for (int j = 0; j < curBannedId.size(); j++)
        {
            if (curBannedId[j] != curUserId[j] && curBannedId[j] != '*')
            {
                can = false;
                break;
            }
        }
        
        if (can) 
        {
            curList.insert(curUserId);
            vis[i] = true;
            
            solve(idx + 1, curList, user_id, banned_id);
            
            curList.erase(curUserId);
            vis[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    solve(0, set<string>(), user_id, banned_id);
    return list.size();
}