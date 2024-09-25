// merge_sort
// 중복 없음
#include <iostream>
using namespace std;

int arr[1000001];
int temp[1000001];

int n;

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++)
	{
		if (lidx == mid) temp[i] = arr[ridx++];
		else if (ridx == en) temp[i] = arr[lidx++];
		else if (arr[lidx] <= arr[ridx]) temp[i] = arr[ridx++];
		else temp[i] = arr[lidx++];
	}

	for (int i = st; i < en; i++) arr[i] = temp[i];
}

void merge_sort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	merge_sort(0, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
	return 0;
}