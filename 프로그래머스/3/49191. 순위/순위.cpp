#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win_lose(n + 1, vector<int>(n + 1, 0));
    for (const auto& result : results)
    {
        int winner = result[0];
        int loser = result[1];
        win_lose[winner][loser] = 1;
        win_lose[loser][winner] = -1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if(win_lose[i][j] == 1 && win_lose[j][k] == 1)
                {
                    win_lose[i][k] = 1;
                    win_lose[k][i] = -1;
                }
                
                if(win_lose[i][j] == -1 && win_lose[j][k] == -1)
                {
                    win_lose[i][k] = -1;
                    win_lose[k][i] = 1;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (win_lose[i][j] != 0) cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    
    return answer;
}