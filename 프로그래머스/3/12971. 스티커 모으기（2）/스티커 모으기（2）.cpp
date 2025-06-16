#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
    int answer = 0;
    if (sticker.size() == 1) return sticker[0];
    
    // 첫번째 스티커 제거한 경우
    dp[0] = dp[1] = sticker[0];
    for (int i = 2; i < sticker.size() - 1; i++)
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    answer = max(answer, dp[sticker.size() - 2]);
    
    // 두번째 스티커 제거한 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    answer = max(answer, dp[sticker.size() - 1]);
    
    return answer;
}