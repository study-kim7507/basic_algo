#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<ll> inputs;

void rev(string& s)
{
	string tmp = "";
	for (int i = s.length() - 1; i >= 0; i--)
		tmp += s[i];
	s = tmp;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--)
	{
		string input;
		cin >> input;
		rev(input);

		inputs.push_back(stoll(input));
	}

	sort(inputs.begin(), inputs.end());

	for (const ll& l : inputs)
		cout << l << "\n";

	return 0;
}