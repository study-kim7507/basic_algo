#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first > b.first) return a.first > b.first;
    else if (a.first == b.first) return a.second < b.second;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m; // {장르, 재생횟수 총합}
    unordered_map<string, vector<pair<int, int>>> mv; // {장르, [{노래 재생횟수, 노래 고유번호}...]}
    for (int i = 0; i < plays.size(); i++)
    {
        m[genres[i]] += plays[i];
        mv[genres[i]].push_back({plays[i], i});
    }
    
    // map을 value기준으로 내림차순 정렬
    vector<pair<int, string>> temp;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        temp.push_back({(*it).second, (*it).first});
    }
    sort(temp.rbegin(), temp.rend());
    
    // 장르 내에서 노래들의 재생횟수를 기준으로 내림차순 정렬
    // 같은 경우 고유번호가 낮은 노래가 먼저
    for (auto it = mv.begin(); it != mv.end(); it++)
    {
        sort((*it).second.begin(), (*it).second.end(), cmp);
    }
    
    // 정답 
    for (int i = 0; i != temp.size(); i++)
    {
        string genre = temp[i].second;
        int cnt = 0;
        for (auto it = mv[genre].begin(); it != mv[genre].end() && cnt < 2; it++, cnt++)
        {
            answer.push_back((*it).second);
        }
    }
    
    
    return answer;
}