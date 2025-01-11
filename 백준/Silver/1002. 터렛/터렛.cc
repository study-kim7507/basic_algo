// 1002. 터렛
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		// 두 중점 사이의 거리
		double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		// 무수히 많음
		if (dist == 0 && r1 == r2) cout << -1 << "\n";

		// 한 점에서 만남 (외접)
		else if (dist == r1 + r2) cout << 1 << "\n";

		// 한 점에서 만남 (내접)
		else if (dist == abs(r1 - r2)) cout << 1 << "\n";

		// 만나지 않음 (외부에서)
		else if (dist > r1 + r2) cout << 0 << "\n";

		// 만나지 않음 (내부에서)
		else if (dist < abs(r1 - r2)) cout << 0 << "\n";

		// 두 점에서 만남
		else if (dist < r1 + r2) cout << 2 << "\n";
	}
	return 0;
}