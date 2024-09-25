// 바퀴의 회전을 deque로 구현
// 시계 방향 회전 -> 맨 앞 원소를 뺴내서 맨 뒤로
// 반시계 방향 회전 -> 맨 뒤 원소를 빼내서 맨 앞으로

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

deque<int> dq[4];				// 총 4개의 톱니바퀴


// TODO: 순차적으로 도는 것이 아닌 한 번에 돌아야함.
void rotation(int curNum, int dir)
{
	int sn[4][2];
	for (int i = 0; i < 4; i++)
	{
		sn[i][0] = dq[i][6];
		sn[i][1] = dq[i][2];
	}
	int curDir = dir;
	// 현재 톱니바퀴 기준 왼쪽
	for (int i = curNum - 1; i >= 0; i--)
	{
		if (sn[i][1] == sn[i + 1][0]) break;		// 맞닿은 부분이 같다면 회전하지 않음
		if (curDir == 1)		// 이전의 톱니바퀴가 시계방향 회전, 서로 다른 극
		{
			auto twelve = dq[i].front();
			dq[i].pop_front();
			dq[i].push_back(twelve);
			curDir = -1;
			
		}
		else if (curDir == -1)	// 이전의 톱니바퀴가 반시계 방향 회전, 서로 다른 극
		{
			// 반대로 회전
			auto twelve = dq[i].back();
			dq[i].pop_back();
			dq[i].push_front(twelve);
			curDir = 1;
		}
	}

	curDir = dir;
	// 현재 톱니바퀴 기준 오른쪽
	for (int i = curNum + 1; i < 4; i++)
	{
		if (sn[i][0] == sn[i - 1][1]) break;		// 맞닿은 부분이 같다면 회전하지 않음
		if (curDir == 1)		// 이전의 톱니바퀴가 시계방향 회전, 서로 다른 극
		{
			auto twelve = dq[i].front();
			dq[i].pop_front();
			dq[i].push_back(twelve);
			curDir = -1;
			
		}
		else if (curDir == -1)	// 이전의 톱니바퀴가 반시계 방향 회전, 서로 다른 극
		{
			// 반대로 회전
			auto twelve = dq[i].back();
			dq[i].pop_back();
			dq[i].push_front(twelve);
			curDir = 1;
		}
	}

	// 현재 톱니바퀴 회전
	if (dir == 1)				// 시계방향 회전
	{
		auto twelve = dq[curNum].back();
		dq[curNum].pop_back();
		dq[curNum].push_front(twelve);
	}
	else if (dir == -1)			// 반시계 방향 회전
	{
		auto twelve = dq[curNum].front();
		dq[curNum].pop_front();
		dq[curNum].push_back(twelve);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++)
	{
		string input;
		cin >> input;

		// 12시방향부터 시계방향 순서대로 주어짐
		// dq의 0번 인덱스는 12시 방향
		// dq의 1번 인덱스는 1시 방향 ...
		for (int j = 0; j < input.size(); j++)
			dq[i].push_back(int(input[j] - '0'));
	}


	int k;
	cin >> k;
	while (k--)
	{
		int num, dir;
		cin >> num >> dir;

		rotation(num - 1, dir);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0 && dq[i][0] == 1) ans += 1;
		if (i == 1 && dq[i][0] == 1) ans += 2;
		if (i == 2 && dq[i][0] == 1) ans += 4;
		if (i == 3 && dq[i][0] == 1) ans += 8;
	}

	cout << ans << "\n";
	return 0;
}