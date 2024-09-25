#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
bool isused[16];
char arr[16];
char input[16];

bool isVowels(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}

// 현재 저장된 글자 수 k
// 자음의 개수 a
// 모음이 하나라도 포함되었는지 여부 b
void func(int k, int a, bool b) 
{
	if (k == l)
	{
		if (b == false || a < 2) return;

		for (int i = 0; i < k; i++)
			cout << arr[i];
		cout << "\n";

		return;
	}

	for (int i = 0; i < c; i++)
	{
		if (!isused[i])
		{
			if (k != 0 && arr[k - 1] > input[i]) continue;
			isused[i] = true;
			arr[k] = input[i];
			
			// 현재 값이 모음인 경우
			if (isVowels(arr[k]))
				func(k + 1, a, true);
			// 자음인 경우
			else
			{
				func(k + 1, a + 1, b);
			}
			
			isused[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
		cin >> input[i];

	sort(input, input + c);
	func(0, 0, false);

	return 0;
}