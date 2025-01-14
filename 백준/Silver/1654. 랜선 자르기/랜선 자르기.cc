// Parametric Search
// 최적화 문제 -> 결정 문제
// (최적화 문제) N개를 만들 수 있는 랜선의 최대 길이
// -> (결정 문제) 랜선의 길이가 X일 때, 랜선이 N개 이상인가 아닌가?

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int k, n;
long long arr[10001];

bool solve(long long x)
{
	long long cnt = 0;
	for (int i = 0; i < k; i++)
		cnt += (arr[i] / x);
	return cnt >= n;
}

int bs(long long st, long long en)
{
	if (st >= en) return st;
	long long mid = (st + en + 1) / 2;
	if (!solve(mid)) return bs(st, mid - 1);
	else return bs(mid, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];


	cout << bs(1, 0x7FFFFFFF) << "\n";

	return 0;
}