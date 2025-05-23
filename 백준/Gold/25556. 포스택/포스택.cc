// BOJ_25556. 포스텍
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
	vector<int> permu(n, 0);
	
	for (int i = 0; i < n; i++)
		cin >> permu[i];

	stack<int> s1;
	stack<int> s2;
	stack<int> s3;
	stack<int> s4;

	for (const auto& e : permu)
	{
		if (s1.empty() || (!s1.empty() && s1.top() < e)) s1.push(e);
		else if (s2.empty() || (!s2.empty() && s2.top() < e)) s2.push(e);
		else if (s3.empty() || (!s3.empty() && s3.top() < e)) s3.push(e);
		else if (s4.empty() || (!s4.empty() && s4.top() < e)) s4.push(e);
		else
		{
			std::cout << "NO" << "\n";
			return 0;
		}
		// std::cout << s1.size() << " " << s2.size() << " " << s3.size() << " " << s4.size() << "\n";
	}

	std::cout << "YES" << "\n";
	return 0;
}