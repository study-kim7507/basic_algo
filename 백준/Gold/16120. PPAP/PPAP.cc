// BOJ_16120. PPAP
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	string temp = "";
	stack<char> s;

	for (int i = 0; i < input.size(); i++)
	{
		char cur = input[i];
		temp += cur;
		s.push(cur);
		
		if (cur == 'P')
		{
			if (temp == "P") 
			{
				// 아무것도 안함
			}
			else if (temp == "PP")
			{
				// 아무것도 안함
			}
			else if (temp == "PPP")
			{
				temp = "PP";
			}
			else if (temp == "PAP")
			{
				temp = "P";
			}
			else if (temp == "PPAP")
			{
				for (int i = 0; i < 4; i++)
					s.pop();
				if (!s.empty() && s.top() == 'P') temp = "PP";
				else temp = "P";
				s.push(cur);
			}
		}
		else if (cur == 'A')
		{
			if (temp == "A")
			{
				temp = "";
			}
			else if (temp == "PA")
			{
				temp = "";
			}
			else if (temp == "PPA")
			{
				// 아무것도 안함
			}
			else if (temp == "PPAA")
			{
				temp = "";
			}
		}
	}

	if (s.size() == 1 && s.top() == 'P') std::cout << "PPAP" << "\n";
	else std::cout << "NP" << "\n";
	return 0;
}