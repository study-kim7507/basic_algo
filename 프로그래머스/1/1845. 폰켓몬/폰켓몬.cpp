#include <vector>
#include <map>
using namespace std;

map<int, int> m;

int solution(vector<int> nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;
    for (int i = 1; i <= 200000; i++)
    {
        if (m[i] != 0) cnt++;
        if (cnt >= nums.size() / 2) return cnt; 
    }
        
    return cnt;
}