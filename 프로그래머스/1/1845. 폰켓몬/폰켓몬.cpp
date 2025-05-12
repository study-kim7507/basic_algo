#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    for (auto& e : nums)
        m[e]++;
    
    int size = nums.size() / 2;
    
    if (m.size() >= size) return size;
    else return m.size();
}