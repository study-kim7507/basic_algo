// 1062.가르침
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool alphabet[26];
vector<string> s;
int result;

void dfs(int cur, int cnt)
{
	if (cnt == 0)
	{
		int tempResult = 0;
		for (auto e : s)
		{
			bool canRead = true;
			for (int i = 0; i < e.size(); i++)
			{
				if (!alphabet[e[i] - 'a'])
				{
					canRead = false;
					break;
				}
			}
			if (canRead) tempResult++;
		}
		result = max(result, tempResult);
		return;
	}


	for (int i = cur; i < 26; i++)
	{
		if (alphabet[i]) continue;
		alphabet[i] = true;
		dfs(i, cnt - 1);
		alphabet[i] = false;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		s.push_back(input);
	}

	if (k < 5)
	{
		cout << 0 << "\n";
		return 0;
	}

	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;

	dfs(0, k - 5); 

	cout << result << "\n";

	return 0;
}