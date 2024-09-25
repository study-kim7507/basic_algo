#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		stack<char> s;
		string cmd;
		cin >> cmd;

		for (char a : cmd)
		{
			if (s.empty() && a == ')')
			{
				s.push(a);
				break;
			}
			if (s.empty() || s.top() == a)
				s.push(a);
			else if (s.top() != a)
				s.pop();
		}

		if (s.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
	return 0;
}