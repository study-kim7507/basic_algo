// 스택을 이용

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd == ".") break;

		stack<char> s;
		bool isCorrect = true;
		for (char a : cmd)
		{
			if (a == '.') break;
			if (a == '(' || a == '[') s.push(a);
			else if (a == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					isCorrect = false;
					break;
				}
				else s.pop();
			}
			else if (a == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					isCorrect = false;
					break;
				}
				else s.pop();
			}
		}
		if (isCorrect && s.empty()) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}