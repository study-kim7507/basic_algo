/*
 * BOJ_10773. 제로
 * https://www.acmicpc.net/problem/10773
*/


// 입력되는 정수가 0일 경우 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
// 스택을 활용. 0일 경우 스택의 탑에 있는 수를 지우고(pop), 아닐 경우 해당 수를 스택에 삽입(push)
// 수를 입력받을 때, 합을 미리 계산하도록 구현
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	stack<int> s;
	long long sum = 0;
	while (k--)
	{
		int n;
		cin >> n;
		if (n == 0 && !s.empty())
		{
			sum -= s.top();
			s.pop();
		}
		else if (n != 0)
		{
			sum += n;
			s.push(n);
		}
	}

	cout << sum << "\n";
	return 0;
}
