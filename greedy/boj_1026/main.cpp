#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];

bool isUsed[51];

bool cmp(const int& left, const int& right)
{
	return left > right;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, cmp);

	long long ans = 0;

	for (int i = 0; i < n; i++)
		ans += (a[i] * b[i]);

	//// 매 시점 가장 큰 B에 가장 작은 A를 곱해서 나가야 함
	//for (int i = 0; i < n; i++)
	//{
	//	int max = -1;
	//	int maxIdx = 0;
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (max < b[j])
	//		{
	//			max = b[j];
	//			maxIdx = j;
	//		}
	//	}
	//	ans += (a[i] * b[maxIdx]);
	//	b[maxIdx] = -1;
	//}


	cout << ans << "\n";
	return 0;
}