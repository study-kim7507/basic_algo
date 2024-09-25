#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int result = 0;
	while (n--)
	{
		stack<char> s;
		string str;
		
		cin >> str;
		for (char a : str)
		{
			if (s.empty() || s.top() != a)
				s.push(a);
			else if (s.top() == a)
				s.pop();
		}

		if (s.empty()) result++;
	}

	cout << result << "\n";
	return 0;
}