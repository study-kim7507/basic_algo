#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> v(n + 1, 0);
    for (int i = 0; i < lost.size(); i++)
        v[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++)
        v[reserve[i]]++;
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == -1)
        {
            if (v[i-1] == 1) 
            {
                v[i-1] = v[i] = 0;
                continue;
            }
            else if (v[i+1] == 1)
            {
                v[i+1] = v[i] = 0;
                continue;
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] != -1) answer++;
    
    return answer;
}