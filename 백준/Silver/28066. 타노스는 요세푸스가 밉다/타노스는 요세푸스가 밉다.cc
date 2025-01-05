// boj_28066. 타노스는 요세푸스가 밉다
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	// 청설모가 1마리 남을 때까지 계속된다.
	while (dq.size() != 1)
	{
		// 남아 있는 청설모가 K 마리보다 적은 경우
		if (dq.size() < k)
		{
			cout << dq.front() << "\n";
			return 0;
		}

		auto st = dq.begin() + 1;
		auto en = st + k - 1;
		dq.erase(st, en);
		dq.push_back(*dq.begin());
		dq.pop_front();
	}

	cout << dq.front() << "\n";
	return 0;
}
