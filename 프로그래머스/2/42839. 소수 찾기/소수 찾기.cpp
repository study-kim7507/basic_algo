#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

string nums = "0123456789";
unordered_map<char, int> m;
vector<int> candi;

void dfs(string cur)
{
    for (int i = 0; i < 10; i++)
    {
        if (m[nums[i]] == 0) continue;
    
        string newNum = cur + nums[i];
        candi.push_back(stoi(newNum));
    
        m[nums[i]]--;
        dfs(cur + nums[i]);
        m[nums[i]]++;
    }
}

bool isPrime(int a)
{
    if (a <= 1) return false; 
    if (a == 2) return true;  

    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0) return false; 
    }

    return true; 
}


int solution(string numbers) {
    for (const auto& e : numbers)
        m[e]++;
    
    dfs("");
    sort(candi.begin(), candi.end());
    candi.erase(unique(candi.begin(), candi.end()), candi.end());
    
    int answer = 0;
    for (const auto& e : candi)
    {
        if (isPrime(e)) answer++;
    }
    
    return answer;
}