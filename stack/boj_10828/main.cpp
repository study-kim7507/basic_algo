/*
 * BOJ_10828. 스택
 * https://www.acmicpc.net/problem/10828 
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> s;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if (cmd == "top")
		{
			if (s.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << s.top() << "\n";
		}
		else if (cmd == "pop")
		{
			if (s.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << s.top() << "\n";
			s.pop();
		}
		else if (cmd == "empty")
		{
			if (s.empty())
			{
				cout << 1 << "\n";
				continue;
			}
			cout << 0 << "\n";
		}
		else if (cmd == "size")
		{
			cout << s.size() << "\n";
		}
	}

	return 0;
}