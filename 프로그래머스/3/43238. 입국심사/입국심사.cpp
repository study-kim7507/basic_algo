// Parametric Search
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solve(long long curTime, const vector<int>& times)
{
    long long cnt = 0;
    for (auto& e : times)
        cnt += (curTime / e);

    std::cout << curTime << " " << cnt << "\n";
    return cnt;
}

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());
    
    long long st = 1;
    long long en = 10000000000000;
    long long answer = 10000000000000;
    
    while (st <= en)
    {
        long long mid = (st + en) / 2;
        if (solve(mid, times) < n) 
            st = mid + 1;
        else 
        {
            answer = min(answer, mid);
            en = mid - 1;
        }
    }
    
    return answer;
}