#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getPriority(char op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    stack<char> s;

    for (char cur : input)
    {
        if (cur >= 'A' && cur <= 'Z') // 피연산자
        {
            cout << cur;
        }
        else if (cur == '(')
        {
            s.push(cur);
        }
        else if (cur == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        }
        else // 연산자
        {
            while (!s.empty() && getPriority(s.top()) >= getPriority(cur))
            {
                cout << s.top();
                s.pop();
            }
            s.push(cur);
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
