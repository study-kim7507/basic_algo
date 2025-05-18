// BOJ_9935. 문자열 폭발
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void debug(stack<char> st)
{
	string cur = "";
	while (!st.empty())
	{
		cur += st.top();
		st.pop();
	}

	reverse(cur.begin(), cur.end());
	std::cout << cur << "\n\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str, boom;
	cin >> str >> boom;

	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		st.push(str[i]);

		// 폭발문자열보다 현재 저장된 문자열의 길이가 길어지는 경우부터 폭발 확인
		if (st.size() >= boom.size())
		{
			string temp = "";
			for (int i = 0; i < boom.size(); i++)
			{
				temp += st.top();
				st.pop();
			}
		
			reverse(temp.begin(), temp.end());
			// 같다면 버리고, 다르다면 다시 스택에 삽입
			if (temp != boom)
			{
				for (const auto& e : temp)
					st.push(e);
			}
		}
		// debug(st);
	}

	string answer = "";
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}

	reverse(answer.begin(), answer.end());
	if (answer.empty()) std::cout << "FRULA" << "\n";
	else std::cout << answer << "\n";
	return 0;
}