// https://blog.encrypted.gg/499

#include <iostream>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x)
{
	int cur = x;
	while (true)
	{
		state[cur] = VISITED;
		cur = arr[cur];
		// 사이클에 포함된 학생 혹은 사이클에 포함되지 않은 학생을 재방문
		// x는 사이클에 포함될 수 없음
		// 지금까지 방문한 학생들은 사이클에 포함되지 않은 학생으로
		if (state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN)
		{
			cur = x;
			while (state[cur] == VISITED)
			{
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		// x가 아닌 다른 학생을 재방문
		if (state[cur] == VISITED && cur != x)
		{
			while (state[cur] != CYCLE_IN)
			{
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			cur = x;
			while (state[cur] != CYCLE_IN)
			{
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		// x를 재방문 -> 사이클 형성
		if (state[cur] == VISITED && cur == x)
		{
			while (state[cur] != CYCLE_IN)
			{
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (state[i] == NOT_VISITED) run(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (state[i] == NOT_CYCLE_IN) cnt++;
		}

		cout << cnt << "\n";
	}
	return 0;
}