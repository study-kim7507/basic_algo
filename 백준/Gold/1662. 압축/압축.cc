// BOJ_1662. 압축
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	stack<int> s;
	
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ')')
		{
			int len = 0;
			while (s.top() != -1)
			{
				len += s.top();
				s.pop();
			}
			s.pop();

			len *= s.top();
			s.pop();
			s.push(len);
		}
		else if (input[i] == '(') s.push(-1);
		else
		{
			if (input[i + 1] == '(') s.push(int(input[i] - '0'));
			else s.push(1);
		}
	}

	int ans = 0;
	while (!s.empty())
	{
		ans += s.top(); s.pop();
	}
	std::cout << ans << "\n";

	return 0;
}