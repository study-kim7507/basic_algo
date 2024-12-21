// BOJ_1759. 암호 만들기
// 최소 한 개의 모음, 두 개의 자음.
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define MAX 15

int L, C;
char arr[MAX];
char a[MAX];
bool visited[MAX];

void solution(int k)
{
	if (k == L)
	{
		int cnt1 = 0; // 모음 개수
		int cnt2 = 0; // 자음 개수
		for (int i = 0; i < L; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				cnt1++;
			else cnt2++;
		}
		if (cnt1 < 1 || cnt2 < 2) return;
		for (int i = 0; i < L; i++)
			cout << arr[i];
		cout << "\n";
		return;
	}

	char temp = 'a' - 1;
	if (k != 0) temp = arr[k - 1];
	for (int i = 0; i < C; i++)
	{
		if (!visited[i] && a[i] > temp)
		{
			visited[i] = true;
			arr[k] = a[i];
			solution(k + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> a[i];

	sort(a, a + C);
	solution(0);
	

	return 0;
}