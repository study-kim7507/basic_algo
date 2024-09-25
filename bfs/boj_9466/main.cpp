// O(N^2) 풀이법
// n명의 학생
// 특정 학생에서 시작해서 n번 안에 시작점으로 돌아오지 않으면 팀을 이루지 못함
// 모든 학생들에 대해 시도 -> 이미 방문한 루트를 또 다시 방문하게 되는 경우가 생김
#include <iostream>
using namespace std;

int arr[100005];
int n;

bool iscycle(int idx)
{
	int cur = idx;

	// 최대 n번 안에 자기 자신으로 돌아오면 팀을 이룸
	for (int i = 0; i < n; i++)
	{
		cur = arr[cur];
		if (cur == idx) return true;
	}

	// n번 안에 자기 자신으로 돌아오지 못하면 팀을 이루지 못함
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (!iscycle(i)) ans++;
		cout << ans << "\n";
	}
	return 0;
}