#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		list<char> l;
		
		auto cursor = l.end();

		for (char a : s)
		{
			if (a == '<')
			{
				if (cursor != l.begin())
				{
					cursor--;
				}
			}
			else if (a == '>')
			{
				if (cursor != l.end())
				{
					cursor++;
				}
			}
			else if (a == '-')
			{
				if (cursor != l.begin())
				{
					cursor = l.erase(--cursor);
				}
			}
			else
			{
				l.insert(cursor, a);
			}
		}
		
		for (char a : l)
		{
			cout << a;
		}
		cout << "\n";
	}
	return 0;
}