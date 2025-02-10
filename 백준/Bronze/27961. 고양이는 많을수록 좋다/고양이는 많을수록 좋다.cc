// 27961. 고양이는 많을수록 좋다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n;
long long cur = 0;
long long result = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	if (n == 0 || n == 1) 
	{
		cout << n << "\n";
		return 0;
	}

	cur = 1;
	result = 1;

	while (cur < n)
	{
		if (cur * 2 < n) cur *= 2;
		else cur += (n - cur);
		result++;
	}
	
	cout << result << "\n";
	return 0;
}