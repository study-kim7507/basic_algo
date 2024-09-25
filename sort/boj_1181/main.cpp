#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> inputs;


bool cmp(const string& a, const string& b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		inputs.push_back(s);
	}

	
	sort(inputs.begin(), inputs.end(), cmp);
	inputs.erase(unique(inputs.begin(), inputs.end()), inputs.end());

	for (const string& s : inputs)
		cout << s << "\n";

	return 0;
}