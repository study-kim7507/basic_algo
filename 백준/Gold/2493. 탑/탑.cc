// BOJ_2493. 탑
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// {탑의 높이, 탑의 번호}
	stack<pair<int, int>> s;
	s.push({ 100000001, 0 });
	for (int i = 1; i <= n; i++)
	{
		int h;
		cin >> h;
		while (s.top().first < h)
			s.pop();
		std::cout << s.top().second << " ";
		s.push({ h, i });
	}
	return 0;
}