#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n;
vector<int> nums;
vector<int> operators;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	for (int i = 0; i < 4; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			operators.push_back(i);
	}

	long long min_ans = numeric_limits<long long>::max();
	long long max_ans = numeric_limits<long long>::lowest();
	do
	{
		long long result = nums[0];
		for (int i = 0; i < operators.size(); i++)
		{
			if (operators[i] == 0)
				result += nums[i + 1];
			else if (operators[i] == 1)
				result -= nums[i + 1];
			else if (operators[i] == 2)
				result *= nums[i + 1];
			else if (operators[i] == 3)
			{
				if (result < 0)
				{
					result = abs(result) / nums[i + 1];
					result *= -1;
				}
				else
				{
					result /= nums[i + 1];
				}
			}	
		}

		min_ans = min(min_ans, result);
		max_ans = max(max_ans, result);

	} while (next_permutation(operators.begin(), operators.end()));
	
	cout << max_ans << "\n";
	cout << min_ans << "\n";
	
	return 0;
}