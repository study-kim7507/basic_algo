// 23841. 데칼코마니
// https://www.acmicpc.net/problem/23841

#include <iostream>
using namespace std;

int n, m;
char picture[51][51];		// 세로(x), 가로(y) 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// 그림 입력
	for (int x = 0; x < n; x++)
	{
		string input;
		cin >> input;
		for (int y = 0; y < input.size(); y++)
			picture[x][y] = input[y];
	}

	// 데칼코마니
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (picture[x][y] != '.')
				picture[x][m - 1 - y] = picture[x][y];
		}
			

	}
		
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			cout << picture[x][y];
		}
		cout << "\n";
	}

	return 0;
}