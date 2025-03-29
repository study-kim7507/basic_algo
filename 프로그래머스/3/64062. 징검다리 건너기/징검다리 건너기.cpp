// 매개변수 탐색

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(const int& num, const int& k, const vector<int>& stones)
{
    int cnt = 0;
    for (auto stone : stones)
    {
        if (stone - num <= 0) 
        {
            cnt++;
            if (cnt >= k) return false;
        }
        else cnt = 0;
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int st = 0;
    int en = *max_element(stones.begin(), stones.end());
    
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (solve(mid, k, stones))
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return st;
}