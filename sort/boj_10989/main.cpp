// 메모리 초과
// 1000000 입력, 범위는 10000보다 작은 수
// 중복된 입력이 있음. 모두 저장할 필요 없음
#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> input;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		input[num]++;
	}

	for (int i = 0; i < 1000001; i++)
	{
		if (input[i] != 0)
		{
			while (input[i]--)
				cout << i << "\n";
		}
	}
	return 0;
}

