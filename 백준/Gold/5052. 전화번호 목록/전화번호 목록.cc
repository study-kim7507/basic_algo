// BOJ_5052. 전화번호 목록
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	
	while (tc--)
	{
		unordered_set<string> phone_numbers_prefix;
		vector<string> phone_numbers;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string phone_number;
			cin >> phone_number;
			phone_numbers_prefix.insert(phone_number);
			phone_numbers.push_back(phone_number);
		}

		bool can = true;
		for (const auto& phone_number : phone_numbers)
		{
			string cur = "";
			for (int i = 0; i < phone_number.size(); i++)
			{
				cur += phone_number[i];
				auto it = phone_numbers_prefix.find(cur);
				if (it != phone_numbers_prefix.end() && (*it) != phone_number)
				{
					can = false;
					break;
				}
			}

			if (!can) break;
		}

		if (!can) std::cout << "NO" << "\n";
		else std::cout << "YES" << "\n";
	}

	return 0;
}