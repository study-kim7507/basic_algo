#include <iostream>
#include <set>
using namespace std;

int n, q;
set<int> attr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		if (num == 1)
			attr.insert(i);
	}

	long long curPos = 1;
	for (int i = 0; i < q; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int num;
			cin >> num;

			if (attr.find(num) != attr.end())
				attr.erase(num);
			else
				attr.insert(num);
		}
		else if (cmd == 2)
		{
			long long num;
			cin >> num;
			curPos = (curPos + num - 1) % n + 1;
		}

		else if (cmd == 3)
		{
			if (attr.empty()) cout << -1 << '\n';
			else
			{
				auto it = attr.lower_bound(curPos);
				if (it != attr.end())
					cout << *it - curPos << '\n';
				else
					cout << n - curPos + *attr.begin() << '\n';
			}
		}
	}

	return 0;
}