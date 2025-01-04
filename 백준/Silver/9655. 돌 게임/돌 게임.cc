// 9655. 돌 게임
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 != 0) cout << "SK" << "\n";
	else cout << "CY" << "\n";

	return 0;
}