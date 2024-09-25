// R : 배열에 들어있는 수들의 순서를 뒤집음
// D : 첫 번째 수를 버리는 함수

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		// 수행할 함수
		string p;
		cin >> p;

		// 배열에 들어있는 수의 개수
		int n;
		cin >> n;

		// 배열에 들어있는 정수
		string arr;
		cin >> arr;

		deque<int> dq;

		// parsing
		string s;
		for (char a : arr)
		{
			if (a == '[' || a == ',' || a == ']')
			{
				if (!s.empty())
				{
					dq.push_back(stoi(s));
				}
				s = "";
				continue;
			}
			s += a;
		}

		if (n == 0 && p.find('D') == string::npos && dq.empty())
		{
			cout << "[]" << "\n";
			continue;
		}

		else if (n == 0 && !dq.empty())
		{
			cout << "error" << "\n";
			continue;
		}
		// true인 경우는 앞에서, false인 경우는 뒤에서
		bool isForward = true;
		
		// 에러인지 확인
		bool isError = false;

		for (char a : p)
		{
			// 방향 전환
			if (a == 'R')
			{
				if (isForward) isForward = false;
				else isForward = true;
			}

			else if (a == 'D')
			{
				if (dq.empty())
				{
					isError = true;
					break;
				}

				// 방향이 앞이면 앞에서 원소를 제거
				if (isForward)
				{
					dq.pop_front();
				}
				else if (!isForward)
				{
					dq.pop_back();
				}
			}
		}

		if (isError) cout << "error" << "\n";
		else
		{
			cout << "[";
			// 방향에 따라 출력을 다르게
			// 앞 방향이라면
			if (dq.empty())
			{
				cout << "";
			}
			else if (isForward)
			{
				for (int i = 0; i < dq.size() - 1; i++)
				{
					cout << dq[i] << ",";
				}
				cout << dq[dq.size() - 1];
			}

			// 뒤 방향이라면
			else
			{
				for (int i = dq.size() - 1; i > 0; i--)
				{
					cout << dq[i] << ",";
				}
				cout << dq[0];
			}
			cout << "]\n";
		}
	}

	return 0;
}