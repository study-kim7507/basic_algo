// �ʱ� Ǯ�� : ��� ���� �ִ� ���� �����ϰ�, n - 1��°���� �̾Ƴ� �� n��° ���� ���
// �޸� ���� 12MB -> ��� ���� ���� �����ϰ� �Ǹ� �ִ� 1500���̹Ƿ� �޸� �ʰ�


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> min_heap;		// �ּ� ��

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	


	cin >> n;
	for (int i = 0; i < n * n; i++)
	{
		int num;
		cin >> num;
		
		if (min_heap.size() < n)
			min_heap.push(num);
		else if (min_heap.top() < num)
		{
			min_heap.pop();
			min_heap.push(num);
		}
	}

	cout << min_heap.top() << "\n";
	

	return 0;
}