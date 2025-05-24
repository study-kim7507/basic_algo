// BOJ_1052. 물병
#include <iostream>
#include <algorithm>
using namespace std;

int cal(int num)
{
	int cnt = 1;
	
	while (num != 1)
	{
		if (num % 2 == 1) cnt++;
		num /= 2;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int i = 0;
	for (i = 0; ; i++)
	{
		if (cal(n) > k) n++;
		else break;
	}

	std::cout << i << "\n";
	return 0;
}