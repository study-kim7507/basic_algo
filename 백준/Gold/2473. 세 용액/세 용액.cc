#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n;
long long inputs[5001];

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	sort(inputs, inputs + n);

	vector<long long> result;

	// lower_bound -> 주어진 배열에서 찾길 원하는 값 이상의 숫자가 처음 나오는 위치를 반환
	long long max = numeric_limits<long long>::max();
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			long long twoSum = inputs[i] + inputs[j];
			int idx = lower_bound(inputs + j + 1, inputs + n, -twoSum) - inputs;

			for (int nxt : {idx - 1, idx, idx + 1})
			{
				if (nxt <= j || nxt >= n) continue;
				long long threeSum = twoSum + inputs[nxt];
				if (std::abs(threeSum) < max)
				{
					max = std::abs(threeSum);
					result.clear();
					result.push_back(inputs[i]);
					result.push_back(inputs[j]);
					result.push_back(inputs[nxt]);
				}
			}
		}
	}

	sort(result.begin(), result.end());
	for (const long long& element : result)
		cout << element << " ";
	return 0;
}