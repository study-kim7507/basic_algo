#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int st = 0;
    int en = people.size() - 1;
    
    int answer = 0;
    while (st <= en)
    {
        if (people[st] + people[en] <= limit)
        {
            st++;
        }
        en--;
        answer++;
    }
    
    return answer;
}