#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m1;                // {장르, 총 재생횟수}
map<string, vector<pair<int, int>>> m2;     // {장르, 해당 곡 인덱스, 해당 곡 재생 횟수}

bool cmp1(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second >= b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    
    // 장르별로 총 재생횟수를 구함
    for (int i = 0; i < genres.size(); i++)
        m1[genres[i]] += plays[i];
    
    for (int i = 0; i < genres.size(); i++)
        m2[genres[i]].push_back({i, plays[i]});

    vector<pair<string, int>> v1(m1.begin(), m1.end());
    
    sort(v1.begin(), v1.end(), cmp1);
    
    vector<int> result;
    for (int i = 0; i < v1.size(); i++)
    {
        string g = v1[i].first;         // 장르
        vector<pair<int, int>> music = m2[g];       // 현재 장르에 속한 곡들
        sort(music.begin(), music.end(), cmp2);     // 정렬
        for (int j = 0; j < music.size() && j < 2; j++)
        {
            result.push_back(music[j].first);
        }
    }
    
    return result;
}