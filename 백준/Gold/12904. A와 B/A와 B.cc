// BOJ_12904. A와 B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s, t;
bool answer = false;
void dfs(string cur)
{
	if (cur.size() == s.size())
	{
		if (cur == s) answer = true;
		return;
	}

	
	if (cur[cur.size() - 1] == 'A')
	{
		cur.pop_back();
		dfs(cur);
	}
	else if (cur[cur.size() - 1] == 'B')
	{
		cur.pop_back();
		reverse(cur.begin(), cur.end());
		dfs(cur);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> t;

	dfs(t);

	if (answer) std::cout << 1 << "\n";
	else std::cout << 0 << "\n";

	return 0;
}