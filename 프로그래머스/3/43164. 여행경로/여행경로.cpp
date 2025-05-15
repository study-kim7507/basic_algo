#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int routeSize;
unordered_map<string, unordered_map<string, int>> vis;
unordered_map<string, vector<string>> um;

vector<vector<string>> routes;

void dfs(string cur, vector<string> route)
{
    route.push_back(cur);
    if (route.size() == routeSize)
    {
        routes.push_back(route);
        return;
    }    
    
    for (string& nxt : um[cur])
    {
        if (vis[cur][nxt] == 0) continue;
            
        vis[cur][nxt]--;
        dfs(nxt, route);
        vis[cur][nxt]++;
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    routeSize = tickets.size() + 1;
    for (int i = 0; i < tickets.size(); i++)
    {
        string st = tickets[i][0];
        for (int j = 1; j < tickets[i].size(); j++)
        {
            string en = tickets[i][j];
            um[st].push_back(en);
            vis[st][en]++;
        }
    }
    for (auto it = um.begin(); it != um.end(); it++)
        sort((*it).second.begin(), (*it).second.end());
    
    dfs("ICN", vector<string>());
    
    return routes[0];
}