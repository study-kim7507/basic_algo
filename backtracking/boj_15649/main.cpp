#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int k)
{
	if (k == m)
	{
		// 출력
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			isused[i] = 1;
			arr[k] = i;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

void func2()
{
	int tempArr[10];
	int pre[10];
	for (int i = 0; i < n; i++)
		tempArr[i] = i + 1;

	bool flag = false;
	do
	{
		flag = false;
		for (int i = 0; i < m; i++)
		{
			if (pre[i] != tempArr[i])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			continue;
		}

		for (int i = 0; i < m; i++)
		{
			cout << tempArr[i] << " ";
			pre[i] = tempArr[i];
		}
		cout << "\n";
	} while (next_permutation(tempArr, tempArr + n));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// func(0);
	func2();

	return 0;
}