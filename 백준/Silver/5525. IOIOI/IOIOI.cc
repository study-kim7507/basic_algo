// BOJ 5525. IOIOI
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	int targetLen = 2 * n + 1;
	string target(targetLen, 'I');
	for (int i = 1; i < targetLen; i += 2)
		target[i] = 'O';

	int ans = 0;

	int idx = 0;
	while (idx < m)
	{
		if (s.substr(idx, targetLen) == target) ans++;
		idx++;
	}

	std::cout << ans << "\n";
	return 0;
}