#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (auto& e : s)
    {
        if (st.empty() && e == ')') return false;
        
        if (e == '(') st.push(e);
        else if (e == ')')
        {
            if (st.top() == '(') st.pop();
        }
    }
    
    return st.empty();
}