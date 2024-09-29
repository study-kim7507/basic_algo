// 2501. 약수 구하기
// https://www.acmicpc.net/problem/2501

// 1부터 n까지 1씩 증가시키면서 나머지가 0이면 약수에 포함
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	vector<int> divisor;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		if (n % i == 0) divisor.push_back(i);

	if (divisor.size() < k) cout << 0 << "\n";
	else cout << divisor[k - 1] << "\n";

	return 0;
}