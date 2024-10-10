#include <iostream>
using namespace std;

int str1Count[26];
int str2Count[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	for (const char& a : str)
		str1Count[a - 'a']++;

	cin >> str;
	for (const char& a : str)
		str2Count[a - 'a']++;

	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans += abs(str1Count[i] - str2Count[i]);

	cout << ans << "\n";
	return 0;
}