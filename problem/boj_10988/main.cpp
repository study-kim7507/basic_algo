// 10988. 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988

// 입력의 크기가 최대 100, 시간 제한이 1초로 O(n^2)으로도 해결 가능
// 두 포인터를 이용하면 O(n)으로 해결이 가능하다

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;
	size_t n = input.size();

	bool isPalindrome = true;
	for (size_t i = 0; i < n; i++)
	{
		if (input[i] != input[n - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome) cout << 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}