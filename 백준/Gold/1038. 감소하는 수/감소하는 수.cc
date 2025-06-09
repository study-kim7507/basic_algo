// BOJ_1038. 감소하는 수
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<long long> decrease;

void dfs(int cur, string temp)
{
	decrease.push_back(stoll(temp));

	for (int i = cur - 1; i >= 0; i--)
	{
		dfs(i, temp + to_string(i));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i <= 9; i++)
		dfs(i, to_string(i));

	sort(decrease.begin(), decrease.end());
	
	if (n >= decrease.size()) std::cout << -1 << "\n";
	else std::cout << decrease[n] << "\n";

	return 0;
}