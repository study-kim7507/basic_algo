// BOJ_19539. 사과나무
// 1. 총 나무 높이의 합은 3의 배수이어야 함.
// 2. 두 물뿌리개를 모두 사용해야하므로, 2증가 물뿌리개를 사용할 수 있는 횟수가 걸리는 총 일수 이상이어야함.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	vector<int> trees(n, 0);
	for (int i = 0; i < n; i++)
		cin >> trees[i];

	int sum = 0;
	int cnt = 0;
	for (int tree : trees)
	{
		sum += tree;
		cnt += tree / 2;
	}
			
	int days = sum / 3;
	if (sum % 3 != 0 || cnt < days)
	{
		std::cout << "NO" << "\n";
		return 0;
	}

	std::cout << "YES" << "\n";
	return 0;
}