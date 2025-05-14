#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct cmp
{
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
    {
        int numA = a.first;
        int numB = b.first;
        
        int reqTimeA = a.second.first;
        int reqTimeB = b.second.first;
        
        int timeTakenA = a.second.second;
        int timeTakenB = b.second.second;
        
        if (timeTakenA != timeTakenB) return timeTakenA > timeTakenB;
        else if (reqTimeA != reqTimeB) return reqTimeA > reqTimeB;
        else return numA > numB;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<int> answer;
    
    // m[요청시각] = {[작업 번호, 소요 시간]...}
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < jobs.size(); i++)
    {
        auto cur = jobs[i];
        m[cur[0]].push_back({i, cur[1]});
    }
    
    // {작업 번호, {요청 시각, 소요 시간}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
    
    int completeCount = 0;
    
    // {작업 번호, {시작 시간, 소요 시간}}
    pair<int, pair<int, int>> hardDisk = {-1, {0, 0}};
    
    for (int i = 0; ; i++)
    {
        if (completeCount == jobs.size()) break;
        
        auto curTimeReqJobs = m[i];
        for (auto& job : curTimeReqJobs)
        {
            // {작업 번호, {요청 시각, 소요 시간}}
            pq.push({job.first, {i, job.second}});
        }
        
        // 현재 하드 디스크에 작업이 있고, 종료되었을 경우 하드 디스크에서 제거
        if (hardDisk.first != -1 && i == hardDisk.second.first + hardDisk.second.second)
        {
            answer.push_back(abs(jobs[hardDisk.first][0] - i));
            hardDisk = {-1, {0, 0}};
            completeCount++;
        }
        
        if (hardDisk.first == -1 && !pq.empty())
        {
            auto top = pq.top(); pq.pop();
            hardDisk = {top.first, {i, top.second.second}};
        }
        
    }
    
    int sum = 0;
    for (const auto& e : answer)
        sum += e;
    return sum / answer.size();
}