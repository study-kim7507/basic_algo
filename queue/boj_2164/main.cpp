// 1번 카드가 제일 위, N번 카드가 제일 아래
// 맨 앞에서 제거, 맨 앞 원소를 맨 뒤로 이동 -> 맨 앞에서 원소를 빼내고, 맨 뒤에 삽입 -> 큐
// 해당 과정을 카드가 한 장 남을 때까지 반복 
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	// 카드가 한 장 남을 때까지 반복
	while (q.size() != 1)
	{
		// 맨 앞 카드 한장 제거
		q.pop();

		// 제거된 이후 맨 앞 카드를 맨 뒤로 이동
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << "\n";

	return 0;
}