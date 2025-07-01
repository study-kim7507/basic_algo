#include <bits/stdc++.h>
using namespace std;

string solution(string str) {
    stack<char> S;
    for (auto ch : str) {
        if (ch == '(' || ch == '[') S.push(ch);
        else if (ch == ')') {
            if (S.empty() || S.top() != '(') return "no";
            S.pop();
        }
        else if (ch == ']') {
            if (S.empty() || S.top() != '[') return "no";
            S.pop();
        }
    }
    if (!S.empty()) return "no";
    return "yes";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while(true) {
        getline(cin, str);
        if (str == ".") break;
        cout << solution(str) << '\n';
    }

    return 0;
}