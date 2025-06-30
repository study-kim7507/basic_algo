#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int N, L;
	cin >> N >> L;

	// <value, index>
	deque<pair<int, int>> dq;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!dq.empty() && dq.back().first >= num)
		{
			dq.pop_back();
		}

		dq.push_back({ num, i });

		if (dq.front().second <= i - L)
		{
			dq.pop_front();
		}

		cout << dq.front().first << " ";
	}

	return 0;
}