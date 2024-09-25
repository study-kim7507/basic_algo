#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> l;
	
	string s;
	cin >> s;
	for (char a : s)
	{
		l.push_back(a);
	}

	auto cursor = l.end();
	
	int n;
	cin >> n;
	while (n--)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'L')
		{
			// 커서를 왼쪽으로 한칸 옮김
			if (cursor != l.begin())
			{
				cursor--;
			}
		}
		else if (cmd == 'D')
		{
			if (cursor != l.end())
			{
				cursor++;
			}
		}
		else if (cmd == 'B')
		{
			if (cursor != l.begin())
			{
				cursor = l.erase(--cursor);
			}
		}
		else if (cmd == 'P')
		{
			char input;
			cin >> input;
			l.insert(cursor, input);
		}
	}

	for (char a : l)
	{
		cout << a;
	}

	return 0;
}