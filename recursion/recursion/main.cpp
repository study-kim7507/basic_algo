// 귀납적 사고. 
	// func1(1)이 1을 출력한다
	// func1(k)가 k, k-1, k-2 ... 1 을 출력한다.
	// -> func1(k+1)은 k+1, k, k-1, k-2 ... 1을 출력한다.
// 재귀 함수의 조건
	// 특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어야 함. (Base condition)
	// 모든 입력은 Base condition으로 수렴해야함.

#include <iostream>
using namespace std;

void func1(int n)
{
	if (n == 0) return; // Base condition
	cout << n << " ";
	func1(n - 1);
}

// a^b mod m
long long func2(long long a, long long b, long long m)
{
	long long val = 1;
	while (b--)
	{
		val = val * a % m;
	}
	return val;
}

int main()
{
	cout << func2(6, 100, 5) << "\n";
	return 0;
}