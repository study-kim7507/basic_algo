#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> pos[100001];
pair<int, int> tmp[100001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++)
	{
		if (lidx == mid) tmp[i] = pos[ridx++];
		else if (ridx == en) tmp[i] = pos[lidx++];
		else if (pos[lidx].second < pos[ridx].second) tmp[i] = pos[lidx++];
		else if (pos[lidx].second > pos[ridx].second) tmp[i] = pos[ridx++];
		else
		{
			if (pos[lidx].first <= pos[ridx].first) tmp[i] = pos[lidx++];
			else tmp[i] = pos[ridx++];
		}
	}

	for (int i = st; i < en; i++)
		pos[i] = tmp[i];
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
		int xpos, ypos;
		cin >> xpos >> ypos;
		pos[i] = { xpos, ypos };
	}

	merge_sort(0, n);

	for (int i = 0; i < n; i++)
		cout << pos[i].first << " " << pos[i].second << "\n";

	return 0;
}