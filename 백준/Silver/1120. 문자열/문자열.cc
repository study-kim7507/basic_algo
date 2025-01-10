// 1120. 문자열
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

string a, b;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b;

	int count = 0;

	// a를 계속 오른쪽으로 하나씩 옮기면서 가장 많이 일치하는 지점을 찾으면 해결
	for (int i = 0; i <= b.size() - a.size(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == b[i + j]) tmp++;
		}
		count = max(count, tmp);
	}

	cout << a.size() - count << "\n";
	return 0;
}