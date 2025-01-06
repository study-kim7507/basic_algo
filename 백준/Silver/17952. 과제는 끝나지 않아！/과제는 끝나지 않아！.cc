// 17952. 과제는 끝나지 않아!
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	deque<pair<int, int>> dq;
	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		int isAssignment, score, remainTime;
		cin >> isAssignment;

		if (isAssignment == 1)
		{
			cin >> score >> remainTime;
			remainTime -= 1;
			if (remainTime == 0) result += score;
			else dq.push_front(make_pair(score, remainTime));
		}
		else if (isAssignment == 0)
		{
			if (!dq.empty())
			{
				dq[0].second -= 1;
				if (dq[0].second == 0)
				{
					result += dq[0].first;
					dq.pop_front();
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}