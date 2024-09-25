#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

// sort���� �����ϴ� ���ذ� �Ųٷ� 2��° ������ �켱������ ���ٸ� true, �ƴ϶�� false
struct cmp
{
	bool operator()(const int& a, const int& b)
	{
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		else if (abs(a) == abs(b)) return a > b;
		return false;
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, cmp> pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (pq.empty()) cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}