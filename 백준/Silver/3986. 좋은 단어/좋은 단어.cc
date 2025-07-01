// BOJ_3986. 좋은 단어
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		stack<char> s;

		cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			if (!s.empty() && s.top() == input[j]) s.pop();
			else s.push(input[j]);
		}

		if (s.empty()) ans++;
	}

	std::cout << ans << "\n";

	return 0;
}