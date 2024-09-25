#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[21][21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	// 0 : 스타트 팀
	// 1 : 링크 팀
	vector<int> combi;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2) combi.push_back(0);
		else combi.push_back(1);
	}

	int ans = 987654321;

	do
	{
		int s_abil = 0;
		int l_abil = 0;
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < combi.size(); i++)
		{
			if (combi[i] == 0) start.push_back(i);
			else if (combi[i] == 1) link.push_back(i);
		}

		for (int i = 0; i < start.size(); i++)
		{
			for (int j = i + 1; j < start.size(); j++)
			{
				int p1 = start[i];
				int p2 = start[j];
				s_abil += board[p1][p2] + board[p2][p1];
			}
		}
		for (int i = 0; i < link.size(); i++)
		{
			for (int j = i + 1; j < link.size(); j++)
			{
				int p1 = link[i];
				int p2 = link[j];
				l_abil += board[p1][p2] + board[p2][p1];
			}
		}
		ans = min(ans, abs(s_abil - l_abil));
	} while (next_permutation(combi.begin(), combi.end()));

	cout << ans << "\n";
	return 0;
}