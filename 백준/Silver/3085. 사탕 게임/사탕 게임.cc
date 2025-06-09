// BOJ_3085. 사탕 게임
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[51][51];

int answer;

void cal()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (board[i][j] == board[i][j + 1]) cnt++;
			else
			{
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
	}

	for (int j = 0; j < n; j++)
	{
		int cnt = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (board[i][j] == board[i + 1][j]) cnt++;
			else
			{
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
			board[i][j] = input[j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < n && board[i][j] != board[i + 1][j])
			{
				swap(board[i][j], board[i + 1][j]);
				cal();
				swap(board[i][j], board[i + 1][j]);
			}

			if (j + 1 < n && board[i][j] != board[i][j + 1])
			{
				swap(board[i][j], board[i][j + 1]);
				cal();
				swap(board[i][j], board[i][j + 1]);
			}
		}
	}


	std::cout << answer << "\n";
	return 0;
}