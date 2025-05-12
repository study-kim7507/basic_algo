#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for (int i = 0 ; i < progresses.size(); i++)
    {
        int qt = (100 - progresses[i]) / speeds[i];
        int rm = (100 - progresses[i]) % speeds[i];
        int day = rm != 0 ? qt + 1 : qt;
        q.push(day);
    }
    
    int cnt = 1;
    int front = q.front();
    q.pop();
    while(!q.empty())
    {
        if (q.front() <= front)
        {
            cnt++;
            q.pop();
        }
        else
        {
            answer.push_back(cnt);
            front = q.front();
            q.pop();
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    return answer;
}