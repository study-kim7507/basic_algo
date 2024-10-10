// 최대 거리 1,000,000,000에서 절반씩 줄여가며 설치가능한 경우의 최대 거리를 찾는 문제 -> 매개 변수 탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, c;
vector<int> pos;

// 주어진 공유기를 모두 설치 가능한지 확인
int solve(ll length)
{
	int cur = pos[0];
	int cnt = 1;
	for (int i = 1; i < pos.size(); i++)
	{
		if (cur + length <= pos[i])
		{
			cur = pos[i];
			cnt++;
		}
	}

	return cnt;
}

int bs(ll st, ll en)
{
	if (st >= en) return st;

	ll mid = (st + en + 1) / 2;
	int cnt = solve(mid);
	if (cnt < c) return bs(st, mid - 1);
	else if (cnt >= c) return bs(mid, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pos.push_back(x);
	}

	sort(pos.begin(), pos.end());
	
	cout << bs(0, 1000000000) << "\n";
	
	return 0;
}