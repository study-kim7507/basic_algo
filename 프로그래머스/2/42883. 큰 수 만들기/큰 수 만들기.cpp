#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    stack<char> s;
    for (int i = 0; i < number.size(); i++)
    {
        while (!s.empty() && k > 0 && s.top() < number[i])
        {
            s.pop();
            k--;   
        }
        s.push(number[i]);
    }
    
    while (k-- != 0 && !s.empty())
        s.pop();
    
    string answer = "";
    while (!s.empty())
    {
        answer = answer + s.top(); s.pop();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}