#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    // 종류에 따라 의상 저장
    map<string, vector<string>> m;
    for (auto& e : clothes)
    {
        m[e[1]].push_back(e[0]);
    }

    int cnt = 1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int size = (*it).second.size();
        cnt *= (size + 1);
    }
    
    answer = cnt - 1;
    return answer;
}