// BOJ 2166. 다각형의 면적
// 서로 다른 두 벡터의 외적의 크기 -> 두 벡터가 형성하는 평행사변형의 크기
// 즉, 특정 한 점과 서로 다른 두 점이 이루는 두 벡터의 사이의 외적의 크기의 절반이 해당 세 점이 이루는 삼각형의 넓이가 됨.
// 이들을 모두 합하면 주어진 점들로부터 구성된 다각형의 넓이가 된다.
// 서로 다른 세점 (0, 0), (a, b), (c, d)에서 서로 다른 두 벡터 (a, b, 0), (c, d, 0)를 얻을 수 있고, 이 두 벡터의 외적은 (0, 0, ad - bc)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define X first
#define Y second

long long tArea(pair<long long, long long> v1, pair<long long, long long> v2)
{
	// 서로 다른 두 벡터의 외적을 기반으로 해당 두 벡터가 이루는 삼각형의 넓이를 계산
	// (a, b), (c, d)

	return v1.X * v2.Y - v1.Y * v2.X;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	vector<pair<int, int>> pos;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
	}

	double ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		ans += tArea(make_pair(pos[i].X - pos[0].X, pos[i].Y - pos[0].Y),
			make_pair(pos[i + 1].X - pos[0].X, pos[i + 1].Y - pos[0].Y));
	}

	ans *= 0.5;

	std::cout << fixed;
	std::cout.precision(1);
	std::cout << abs(round(ans * 10) / 10) << "\n";

	return 0;
}