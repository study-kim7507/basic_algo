// BOJ_1107.리모컨
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

unordered_set<int> notBroken;
vector<int> candi;

void dfs(int depth, string cur)
{
	if (depth > 5)
	{
		if (cur.empty()) return;
		candi.push_back(stoi(cur));
		return;
	}

	for (auto e : notBroken)
	{
		if (e == -1) dfs(depth + 1, cur);
		else dfs(depth + 1, cur + to_string(e));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	notBroken.insert(-1);
	for (int i = 0; i <= 9; i++)
		notBroken.insert(i);

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		notBroken.erase(num);
	}

	dfs(0, "");
	sort(candi.begin(), candi.end());
	int answer = 0x3f3f3f3f;
	for (auto e : candi)
	{
		answer = min(answer, (int)(abs(n - e) + to_string(e).size()));
	}
	answer = min(answer, abs(100 - n));

	std::cout << answer << "\n";
	return 0;
}