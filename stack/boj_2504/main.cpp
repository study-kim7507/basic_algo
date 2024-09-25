// (, [ 라면 각 괄호에 맞는 값을 tempResult에 곱해준다.
// 이전 괄호가 (, [ 이었고, 현재 괄호가 ), ]라면 tempResult의 값을 result에 저장
// 이후, 괄호를 스택에서 제거하고 각 값에 맞도록 tempResult를 나눠준다

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int result = 0;
	int tempResult = 1;
	stack<char> s;

	for (int i = 0; i < str.length(); i++)
	{
		if (s.empty() && (str[i] == ')' || str[i] == ']'))
		{
			s.push(str[i]);
			break;
		}

		if (str[i] == '(')
		{
			tempResult *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[')
		{
			tempResult *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')' && str[i - 1] == '(')
		{
			result += tempResult;
			tempResult /= 2;
			s.pop();
		}
		else if (str[i] == ']' && str[i - 1] == '[')
		{
			result += tempResult;
			tempResult /= 3;
			s.pop();
		}
		else if (str[i] == ')' && s.top() == '(')
		{
			tempResult /= 2;
			s.pop();
		}
		else if (str[i] == ']' && s.top() == '[')
		{
			tempResult /= 3;
			s.pop();
		}
	}

	if (s.empty()) cout << result << "\n";
	else cout << 0 << "\n";
	return 0;
}