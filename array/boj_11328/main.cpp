#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	while(n--)
	{
		int isIn[26] = { 0 };
		bool isCan = true;
		string s1, s2;
		cin >> s1 >> s2;

		for (char a : s1)
		{
			isIn[a - 'a']++;
		}

		for (char a : s2)
		{
			// 만약 존재하지 않은 스펠링이 있다면
			if (isIn[a - 'a']-- == 0)
			{
				isCan = false;
				break;
			}
		}

		if (s1.length() != s2.length())
		{
			isCan = false;
		}

		if (isCan) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
	return 0;
}