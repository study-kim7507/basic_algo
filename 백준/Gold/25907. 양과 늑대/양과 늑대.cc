// 25907. 양과 늑대 - 인터랙티브
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int st = 1;
	int en = n;
	for (int i = 0; i < 20; i++)
	{
		int day = (st + en) / 2;		// day날의 양의 마리 수를 질문함
		cout << "? " << day << endl;	// endl은 버퍼 flush까지 해줌
		
		int ans;
		cin >> ans;						// 질문에 대한 답. mid날에 양의 마리 수

		// day날에 양이 더 많은 경우
		if (day - ans < ans)
		{
			st = day + 1;
		}
		// day날에 늑대가 더 많은 경우
		else if (day - ans > ans)
		{
			en = day - 1;
		}
		// day날에 양과 늑대의 수가 동일한 경우
		else if (day - ans == ans)
		{
			cout << "! " << day << endl;
			return 0;
		}
	}

	cout << "! " << 0 << endl;
	return 0;
}