// 소수 판정법 : 에라토스 테네스의 체
#include <iostream>
using namespace std;

int n;
int arr[1001];
int input[101];

void eratos()
{
	arr[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = 2; j * i < 1001; j++)
				arr[j * i] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	eratos();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[input[i]] == 0)
			ans++;
	}
	cout << ans << "\n";

	return 0;
}