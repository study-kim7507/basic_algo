// 나이가 같으면 가입한 순서 -> stable sort
// merge sort 이용
#include <iostream>
using namespace std;

int n;
pair<int, string> member[100001];
pair<int, string> tmp[100001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++)
	{
		if (lidx == mid) tmp[i] = member[ridx++];
		else if (ridx == en) tmp[i] = member[lidx++];
		else if (member[lidx].first <= member[ridx].first) tmp[i] = member[lidx++];
		else tmp[i] = member[ridx++];
	}

	for (int i = st; i < en; i++) member[i] = tmp[i];
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
	{
		int age;
		string name;
		cin >> age >> name;
		member[i] = { age, name };
	}
	
	merge_sort(0, n);

	for (int i = 0; i < n; i++)
		cout << member[i].first << " " << member[i].second << "\n";

	return 0;
}

