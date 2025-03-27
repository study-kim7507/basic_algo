// 25542. 약속 장소
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, l;
vector<string> names;
string result = "";

void dfs(int idx, string cur)
{
	if (cur.size() == l)
	{
		for (string name : names)
		{
			int diff = 0;
			for (int idx = 0; idx < l; idx++)
			{
				if (name[idx] != cur[idx]) diff++;
			}

			if (diff > 1)
			{
				if (result == "") result = "CALL FRIEND";
				return;
			}
		}
		result = cur;
		return;
	}

	vector<int> v(26);

	for (string name : names)
		v[name[idx] - 'A']++;

	int num = *max_element(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
		{
			dfs(idx + 1, cur + (char)(i + 'A'));
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		names.push_back(name);
	}

	dfs(0, "");
	cout << result << "\n";

	return 0;
}