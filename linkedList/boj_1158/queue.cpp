#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	
	cout << "<";
	// 큐가 빌때까지 반복
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (q.size() != 0)
		{
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}