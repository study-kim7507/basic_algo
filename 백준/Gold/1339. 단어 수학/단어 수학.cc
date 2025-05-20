// BOJ_1339. 단어수학
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_map<char, int> um;

	int n;
	cin >> n;
	vector<string> inputs;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		inputs.push_back(str);
		for (int j = 0; j < str.size(); j++)
		{
			int num = pow(10, str.size() - j - 1);
			um[str[j]] += num;
		}
	}

	vector<pair<int, char>> v;
	for (auto it = um.begin(); it != um.end(); it++)
		v.push_back({ (*it).second, (*it).first });
	sort(v.rbegin(), v.rend());

	int num = 9;
	for (int i = 0; i < v.size(); i++)
		um[v[i].second] = num--;

	int answer = 0;
	for (const auto& e : inputs)
	{
		for (int i = 0; i < e.size(); i++)
		{
			int num = pow(10, e.size() - i - 1);
			num *= um[e[i]];
			answer += num;
		}
	}

	std::cout << answer;
	return 0;
}