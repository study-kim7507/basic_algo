// A의 아스키코드 값은 65

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string n;
int b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> b;

	int ans = 0;
	for (int i = 0; i < n.size(); i++)
	{
		int idx = n.size() - i - 1;
		int cur = 0;

		if (n[idx] < 'A') cur = int(n[idx] - '0');
		else cur = int(n[idx] - 55);
		ans += (cur * pow(b, i));
	}

	cout << ans << "\n";
	return 0;
}