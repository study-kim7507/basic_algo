// 14719. 빗물
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
int arr[501];

int calMaxHeight(int st, int en)
{
	int result = -1;
	for (int i = st; i <= en; i++)
		result = max(result, arr[i]);
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;
	for (int i = 0; i < w; i++)
		cin >> arr[i];
		

	int result = 0;
	for (int i = 1; i < w - 1; i++)
	{
		int currHeight = arr[i];
		int leftMaxHeight = calMaxHeight(0, i - 1);
		int rightMaxHeight = calMaxHeight(i + 1, w - 1);
		int currResult = min(leftMaxHeight, rightMaxHeight) - currHeight;
		if (currResult >= 0)
			result += currResult;
	}

	cout << result << "\n";
	return 0;
}