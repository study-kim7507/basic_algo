#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[3] = { 1, 2, 3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i] << " ";
		cout << "\n";
	} while (next_permutation(a, a + 3));


	// 5개 중 3개를 뽑는 조합 문제
	int b[5] = { 0, 0, 0, 1, 1 };
	do {
		for (int i = 0; i < 5; i++)
		{
			if (b[i] == 0)
				cout << i + 1;
		}
		cout << "\n";
	} while (next_permutation(b, b + 5));

	return 0;
}

