#include <iostream>
using namespace std;

int k;
int input[14];
int arr[14];


void func(int cur, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << "\n";
		
		return;
	}

	for (int i = cur; i < k; i++)
	{
		arr[cnt] = input[i];
		func(i + 1, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	while (true)
	{
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++)
			cin >> input[i];
		func(0, 0);
		cout << "\n";
	}

	return 0;
}