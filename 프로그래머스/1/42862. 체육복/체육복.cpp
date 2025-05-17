#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> lostM;
map<int, int> reserveM;

int solution(int n, vector<int> lost, vector<int> reserve) {
    for (int i = 0; i < lost.size(); i++)
        lostM[lost[i]]++;
    for (int i = 0; i < reserve.size(); i++)
        reserveM[reserve[i]]++;
    
    for (auto it1 = reserveM.begin(); it1 != reserveM.end(); it1++)
    {
        for (auto it2 = lostM.begin(); it2 != lostM.end(); it2++)
        {
            if ((*it2).second >= 1 && (*it1).second >= 1 && (*it1).first == (*it2).first)
            {
                (*it2).second--;
                (*it1).second--;
            }
        }
    }
    
    for (auto it1 = reserveM.begin(); it1 != reserveM.end(); it1++)
    {
        for (auto it2 = lostM.begin(); it2 != lostM.end(); it2++)
        {
            if ((*it2).second >= 1 && (*it1).second >= 1 && abs((*it1).first - (*it2).first) <= 1)
            {
                (*it2).second--;
                (*it1).second--;
            }
        }
    }
    
    int answer = n;
    for (auto it = lostM.begin(); it != lostM.end(); it++)
    {
        if ((*it).second != 0) answer--;
    }
    
    return answer;
}