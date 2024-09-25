// 소수 판정법 : 에라토스 테네스의 체
#include <iostream>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i < 1001; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = 2; j * i < 1001; j++)
				arr[j * i] = 1;
		}
	}
	for (int i = 2; i < 1001; i++)
	{
		if (arr[i] == 0)
			cout << i << " ";
		if (i % 20 == 0) cout << "\n";
	}

	return 0;
}