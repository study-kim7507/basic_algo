// 하노이 탑 이동 순서
// 예시에서 세 번째 장대로 3번 원판을 옮기기 위해선
// 1, 2번 원판은 두 번째 장대에 모두 존재해야 함.

#include <iostream>
using namespace std;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력
void func(int a, int b, int n)
{
	// 원판이 1개라면 출력
	if (n == 1)
	{
		cout << a << ' ' << b << "\n";
		return;
	}
	// 원판이 한 개가 아니라면, n - 1개를 6-a-b로 옮김
	func(a, 6 - a - b, n - 1);
	
	// n번 원판을 기둥 a에서 기둥 b로 옮김
	cout << a << ' ' << b << "\n";

	// n - 1개의 원판을 기둥 6-a-b에서 기둥 b로 옮김
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;
	cout << (1 << k) - 1 << "\n";
	func(1, 3, k);

	return 0;
}