#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> v;

bool cmp(const string& a, const string& b)
{
	int length = a.length() <= b.length() ? a.length() : b.length();
	for (int i = 0; i < length; i++)
	{
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}

	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		string tmp = "";
		for (auto j = i; j < s.length(); j++)
			tmp += s[j];
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);

	for (const string& s : v)
		cout << s << "\n";
	return 0;
}