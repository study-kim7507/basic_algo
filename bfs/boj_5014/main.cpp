// F : 건물의 높이
// S : 강호의 시작점
// G : 스타트링크 위치 (도착점)
// U : +U만큼 이동
// D : -D만큼 이동

#include <iostream>
#include <queue>
using namespace std;

int building[1000001];

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	
	// 도착점
	building[G] = 0;

	// 시작점
	building[S] = 1;
	queue<int> q;
	q.push({ S });
	while (!q.empty() && building[G] == 0)
	{
		auto cur = q.front(); q.pop();
		for (int nxt : {cur + U, cur - D})
		{
			if (nxt <= 0 || nxt > F) continue;
			if (building[nxt] != 0) continue;
			q.push({ nxt });
			building[nxt] = building[cur] + 1;
		}
	}

	if (building[G] == 0)
	{
		cout << "use the stairs" << "\n";
		return 0;
	}
	cout << building[G] - 1 << "\n";
	return 0;
}