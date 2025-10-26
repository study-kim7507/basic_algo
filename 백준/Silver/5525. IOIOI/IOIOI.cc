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

	int ans = 0;
	int cnt = 0;
	for (int i = 1; i < m - 1; i++)
	{
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') 
		{
			cnt++;
			if (cnt == n)
			{ 
				ans++;
				cnt--;
			}
			i++; 
		}
		else cnt = 0;
	}



	std::cout << ans << "\n";
	return 0;
}