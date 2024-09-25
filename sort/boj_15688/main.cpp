// counting sort
#include <iostream>
#include <map>
using namespace std;

int n;
int cnt[2000002];				// -1,000,000 ~ 1,000,000
								// 0 ~ 1,000,000 


map<int, int> cnt2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	int num;
	//	cin >> num;
	//	if (num < 0)
	//		cnt[1000000 - abs(num)]++;
	//	else
	//		cnt[num + 1000000]++;
	//}

	//for (int i = 0; i < 2000002; i++)
	//{
	//	if (cnt[i] == 0) continue;
	//	if (i < 1000000)
	//	{
	//		for (int j = 0; j < cnt[i]; j++)
	//			cout << i - 1000000 << "\n";
	//	}
	//	else if (i >= 1000000)
	//	{
	//		for (int j = 0; j < cnt[i]; j++)
	//			cout << i - 1000000 << "\n";
	//	}
	//}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		cnt2[num]++;
	}

	for (int i = -1000000; i < 1000001; i++)
	{
		if (cnt2[i] != 0)
		{
			for (int j = 0; j < cnt2[i]; j++)
				cout << i << "\n";
		}
	}
	return 0;
}