// BOJ 2805. 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> inputs;

bool solve(long long curHeight)
{
	long long sum = 0;

	for (int i = 0; i < n; i++)
		sum += max(0LL, inputs[i] - curHeight);

	return sum >= m;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int len;
		cin >> len;
		inputs.push_back(len);
	}
	
	long long st = 0;
	long long en = 0x7fffffff;

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	std::cout << st << "\n";

	return 0;
}