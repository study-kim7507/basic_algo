// BOJ_1239. 차트
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int answer = 0;

	// 하나라도 50을 넘어가면 중앙을 선을 갖는 차트를 만들 수 없음.
	if (v[v.size() - 1] > 50)
	{
		std::cout << answer << "\n";
		return 0;
	}

	
	do
	{
		int cnt = 0;

		for (int st = 0; st < v.size(); st++) {
			int sum = 0;
			int tmp_idx = st;
			while (sum < 50) {
				sum += v[tmp_idx];
				tmp_idx = (tmp_idx + 1) % v.size();
			}
			cnt += (sum == 50);
		}
		answer = max(answer, cnt);
	} while (next_permutation(v.begin(), v.end()));

	std::cout << answer / 2 << "\n";
	return 0;
}