// BOJ_ 1316. 그룹 단어 체커
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int tc;
	cin >> tc;

	int answer = 0;
	while (tc--)
	{
		bool isGroup = true;
		unordered_map<char, vector<int>> um;

		string input;
		cin >> input;
		for (int i = 0; i < input.size(); i++)
		{
			if (um[input[i]].empty()) um[input[i]].push_back(i);
			else
			{
				if (abs(um[input[i]][um[input[i]].size() - 1] - i) > 1)
				{
					isGroup = false;
					break;
				}
				else um[input[i]].push_back(i);
			}
		}

		if (isGroup) answer++;
	}
	
	std::cout << answer << "\n";

	return 0;
}