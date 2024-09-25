// 정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로
// 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 방법
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int arr2[100001];

bool bs(int st, int en, int target)
{
	if (st > en) return false;
	int mid = (st + en) / 2;
	if (arr[mid] == target) return true;
	else if (arr[mid] > target) return bs(st, mid - 1, target);
	else if (arr[mid] < target) return bs(mid + 1, en, target);	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	sort(arr, arr + n);

	for (int i = 0; i < m; i++)
		cout << static_cast<int>(bs(0, n - 1, arr2[i])) << "\n";

	return 0;
}