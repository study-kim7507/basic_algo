// BOJ_2504. 괄호의 값
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;
	
	int ans = 0, tmp = 1;
	stack<char> s;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' || input[i] == '[')
		{
			tmp *= input[i] == '(' ? 2 : 3;
			s.push(input[i]);
		}
		else
		{
			if (s.empty()) 
			{
				std::cout << 0 << "\n";
				return 0;
			}

			if (input[i] == ')')
			{
				if (s.top() != '(')
				{
					std::cout << 0 << "\n";
					return 0;
				}

				if (input[i - 1] == '(') ans += tmp;
				
				tmp /= 2;
				s.pop();
			}
			else if (input[i] == ']')
			{
				if (s.top() != '[')
				{
					std::cout << 0 << "\n";
					return 0;
				}

				if (input[i - 1] == '[') ans += tmp;

				tmp /= 3;
				s.pop();
			}
		}
	}

	if (!s.empty()) std::cout << 0 << "\n";
	else std::cout << ans << "\n";

	return 0;
}