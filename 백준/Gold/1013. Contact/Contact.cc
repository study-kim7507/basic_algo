// BOJ_1013. Contact
#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string input;
		cin >> input;

		regex re("(100+1+|01)+");

		if (regex_match(input, re))
			std::cout << "YES" << "\n";
		else
			std::cout << "NO" << "\n";
	}

	return 0;
}