#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string cmd;
	cin >> cmd;

	int result = 0;
	stack<char> s;
	
	for (int i = 0; i < cmd.length(); i++)
	{
		if (cmd[i] == '(')
		{
			s.push(cmd[i]);
			
			// 현시점에서는 괄호의 시작이 레이저인지, 막대기의 시작점인지 알 수 없음
			result++;
		}

		if (cmd[i] == ')' && cmd[i - 1] == '(')
		{
			// 이전의 입력이 여는 괄호였고, 현시점의 입력이 닫는 괄호라면 해당부분은 레이저에 해당
			result--;
			s.pop();
			result += s.size();
		}
		else if (cmd[i] == ')')
		{
			s.pop();
		}
	}
	
	cout << result << "\n";
	return 0;
}