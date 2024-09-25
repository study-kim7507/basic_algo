/*
 * BOJ_2493. 탑
 * https://www.acmicpc.net/problem/2493
*/


// 입력을 받으면서 스택에 삽입
// 스택에 삽입 전, 현재 스택의 탑이 입력 받은 값보다 큰 경우, 결과에 기록
// 스택에 삽입 전, 현재 스택의 탑이 입력 받은 값보다 작은 경우, 큰 값을 만날 때까지 원소를 스택의 탑에서 삭제

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> result;
	stack<pair<int, int>> s; // <val, idx>
	for (int i = 1; i <= n; i++)
	{
		int topHeight;
		cin >> topHeight;

		if (s.empty())
		{
			result.push_back(0);
			s.push({ topHeight, i });
		}
		else if (s.top().first > topHeight)
		{
			result.push_back(s.top().second);
			s.push({ topHeight, i });
		}
		else if (s.top().first < topHeight)
		{
			while (!s.empty() && s.top().first < topHeight)
			{
				s.pop();
			}
			if (s.empty())
			{
				result.push_back(0);
				s.push({ topHeight, i });
			}
			else if (s.top().first > topHeight)
			{
				result.push_back(s.top().second);
				s.push({ topHeight, i });
			}
		}
	}

	for (int i : result)
	{
		cout << i << " ";
	}
	return 0;
}