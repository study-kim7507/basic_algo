#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			if (k != 0 && arr[k - 1] > i) continue;
			arr[k] = i;
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}
}

void func2()
{
	// 조합을 이용
	int tempArr[10];
	fill(tempArr, tempArr + 10, 1);
	for (int i = 0; i < m; i++) tempArr[i] = 0;

	do
	{
		for (int i = 0; i < n; i++)
			if (tempArr[i] == 0) cout << i + 1 << " ";
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