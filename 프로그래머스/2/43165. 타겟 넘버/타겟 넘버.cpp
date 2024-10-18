#include <string>
#include <vector>

using namespace std;


int result = 0;
void dfs(vector<int> numbers, int idx, int sum, int target)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            result++;
        return;
    }
    
    dfs(numbers, idx + 1, sum + numbers[idx], target);
    dfs(numbers, idx + 1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    
    return result;
}