#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int idx, int cur, int target)
{
    if (idx == numbers.size())
    {
        if (cur == target) answer++;
        return;
    }
    
    dfs(numbers, idx + 1, cur + numbers[idx], target);
    dfs(numbers, idx + 1, cur + (numbers[idx] * -1), target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    
    return answer;
}