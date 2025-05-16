#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int answer = 987654321;
unordered_map<string, vector<string>> m;
unordered_map<string, bool> vis;

void dfs(string cur, string target, int depth)
{
    if (cur == target)
    {
        answer = min(answer, depth);
        return;
    }
    
    for (auto& nxt : m[cur])
    {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, target, depth + 1);
        vis[nxt] = false;
    }
}

// a와 b를 비교해서 차이가 1개 인지 확인
bool calDiff(const string& a, const string& b)
{
    int diffCount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i]) diffCount++;
    }
    
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
    // begin과 words 비교
    for (const auto& word : words)
    {
        if (calDiff(begin, word)) m[begin].push_back(word);
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i == j || !calDiff(words[i], words[j])) continue;
            m[words[i]].push_back(words[j]);
        }
    }
    
    dfs(begin, target, 0);
    
    if (answer != 987654321) return answer;
    return 0;
}