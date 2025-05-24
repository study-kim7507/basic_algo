// BOJ_2023. 신기한 소수
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> answer;

pair<int, int> range[9] =
{
	{0, 0},
	{1, 9},
	{10, 99},
	{100, 999},
	{1000, 9999},
	{10000, 99999},
	{100000, 999999},
	{1000000, 9999999},
	{10000000, 99999999}
};

bool f_isPrime(int num)
{
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int rangeSt = range[n].first;
	int rangeEn = range[n].second;

	vector<int> result;
	for (int cur = rangeSt; cur <= rangeEn; cur++)
	{
		bool isPrimeCandi = true;
		string curToString = to_string(cur);
		for (int i = 0; i < curToString.size(); i++)
		{
			int curNum = int(curToString[i] - '0');
			if (i == 0)
			{
				if (curNum != 2 && curNum != 3 && curNum != 5 && curNum != 7)
				{
					isPrimeCandi = false;
					break;
				}
			}
			else
			{
				if (curNum % 2 == 0)
				{
					isPrimeCandi = false;
					break;
				}
			}
		}
		if (isPrimeCandi)
		{
			bool isPrime = true;
			string curNum = "";
			for (int i = 0; i < curToString.size(); i++)
			{
				curNum += curToString[i];
				if (!f_isPrime(stoi(curNum)))
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				answer.push_back(cur);
		}
	}
	
	for (auto e : answer)
	{
		std::cout << e << "\n";
	}
	return 0;
}
