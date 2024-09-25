// 회전하는 큐
// 1. 첫번째 원소를 뽑아낸다. 
// 2. 왼쪽으로 한 칸 이동시킨다 -> 맨 앞 원소를 빼내 맨 뒤로 이동
// 3. 오른쪽으로 한 칸 이동시킨다 -> 맨 뒤 원소를 빼내 맨 앞으로 이동
// -> 맨 앞, 맨 뒤 원소를 삽입/삭제 하는 연산이 필요 -> deque

#include<iostream>
#include<deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 큐의 크기, 뽑아내려고 하는 수의 개수
	int n, m;
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	// 뽑아내려는 수
	vector<int> v;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}


	int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		auto idx = find(dq.begin(), dq.end(), v[i]);
		// 앞에서 접근할 때 걸리는 비용 계산
		int front_dist = (distance(dq.begin(), idx));

		// 뒤에서 접근할 때 걸리는 비용 계산
		int back_dist = abs(distance(dq.end(), idx));
		
		// 더 적은 비용이 드는 연산을 반복
		if (front_dist <= back_dist)
		{
			// 앞에서 접근하는 것이 더 가까운 경우
			// 2번 연산을 반복
			for (int j = 0; j < front_dist; j++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				result++;
			}
		}
		else
		{
			// 뒤에서 접근하는 것이 더 가까운 경우
			for (int j = 0; j < back_dist; j++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				result++;
			}
		}
		dq.pop_front();
	}
	
	cout << result << "\n";
	return 0;
}