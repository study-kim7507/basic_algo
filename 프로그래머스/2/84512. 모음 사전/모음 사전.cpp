#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> candi;
const string alphabet = "AEIOU";
    
void solve(string cur, int curLength, int targetLength)
{
    if (curLength == targetLength)
    {
        candi.push_back(cur);
        return;
    }
    
    for (int i = 0; i < alphabet.size(); i++)
    {
        solve(cur + alphabet[i], curLength + 1, targetLength);
    }
}

int solution(string word) {
    
    // word의 길이는 1 이상 5 이하.
    for (int i = 1; i <= 5; i++)
    {
        solve("", 0, i);
    }
    
    sort(candi.begin(), candi.end());
    for (int i = 0; i < candi.size(); i++)
    {
        if (candi[i] == word) return i + 1;
    }
    
    return 0;
}