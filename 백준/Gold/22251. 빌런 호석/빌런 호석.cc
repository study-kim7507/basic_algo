// BOJ_22251. 빌런 호석
#include <iostream>
#include <algorithm>

using namespace std;

string num[10] =
{
	"1111110",
	"0110000",
	"1101101",
	"1111001",
	"0110011",
	"1011011",
	"1011111",
	"1110000",
	"1111111",
	"1111011",
};

int diff[10][10];

int answer = 0;
int n, k, p, x;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int diffCount = 0;
			for (int k = 0; k < 7; k++)
			{
				if (num[i][k] != num[j][k]) diffCount++;
			}
			diff[i][j] = diffCount;
		}
	}

	cin >> n >> k >> p >> x;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;	// 현재 층인 경우 건너 뜀

		int diffCount = 0;
		int from = x, to = i;
		for (int j = 0; j < k; j++)
		{
			diffCount += diff[from % 10][to % 10];
			from /= 10;
			to /= 10;
		}
		
		// std::cout << diffCount << "\n";

		if (diffCount <= p) answer++;
	}

	std::cout << answer << "\n";
	return 0;
}