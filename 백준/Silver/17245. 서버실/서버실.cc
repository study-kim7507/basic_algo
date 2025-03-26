// 17245. 서버실
#include <iostream>
#include <algorithm>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n;
long long total;
int board[1001][1001];

long long solve(int time)
{
	long long result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 합 계산
			if (board[i][j] <= time) result += board[i][j];
			else result += time;
		}
	}
	
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			total += board[i][j];
		}
	}
			
	int st = 0;
	int en = 10000000;
	int ans = 0;
	while (st <= en)
	{
		int mid = (st + en) / 2;

		long long result = solve(mid);
		
		// for debugging
		// cout << st << " " << en << " " << mid << " " << result << "\n";

		if ((double)total / 2.0 <= result)
		{
			en = mid - 1;
			ans = mid;
		}

		else st = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}