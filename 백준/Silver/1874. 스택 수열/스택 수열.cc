/*
 * BOJ_1874. 스택 수열
 * https://www.acmicpc.net/problem/1874
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<char> result; // 결과 저장을 위한 벡터
	stack<int> s;
	int max = 0; // 현재까지 스택에 들어간 최고값을 기록
	while (n--)
	{
		int k;
		cin >> k;
		
		// 현재까지 어떠한 수도 스택에 들어간 적이 없음
		if (max == 0)
		{
			for (int i = 0; i < k; i++)
			{
				s.push(++max);
				result.push_back('+');
			}
		}
		// 현재까지 스택에 들어간 최고값이 현재 입력보다 적은 경우 해당 수까지 스택에 넣음
		else if (max < k)
		{
			while (max != k)
			{
				s.push(++max);
				result.push_back('+');
			}
		}
		
		if (s.top() > k)
		{
			cout << "NO" << "\n";
			return 0;
		}
		while (!s.empty())
		{
			if (s.top() == k) break;
			s.pop();
			result.push_back('-');
		}
		if (!s.empty() && s.top() == k)
		{
			s.pop();
			result.push_back('-');
		}
	}

	for (char a : result)
	{
		cout << a << "\n";
	}
	return 0;
}