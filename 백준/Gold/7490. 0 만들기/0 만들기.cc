// BOJ_7490. 0 만들기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

char n;
vector<string> answer;

bool calculate(string curString)
{
	vector<int> num;
	vector<int> op;			// 0 : +, 1 : -

	string strToNum = "";
	for (int i = 0; i < curString.size(); i++)
	{
		if (curString[i] == '+' || curString[i] == '-')
		{
			num.push_back(stoi(strToNum));
			if (curString[i] == '+') op.push_back(0);
			else op.push_back(1);
			strToNum = "";
		}
		else
		{
			if (curString[i] == ' ') continue;
			else strToNum += curString[i];
		}
	}
	num.push_back(stoi(strToNum));

	int calAns = num[0];
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == 0) calAns += num[i + 1];
		else if (op[i] == 1) calAns -= num[i + 1];
	}

	if (calAns == 0) return true;
	return false;
}

void dfs(char cur, string curString)
{
	curString += cur;

	if (cur == n)
	{
		if (calculate(curString)) answer.push_back(curString);
		return;
	}

	for (char op : {'+', '-', ' '})
	{
		curString.push_back(op);
		dfs(cur + 1, curString);
		curString.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		answer.clear();
		cin >> n;
		dfs('1', "");

		sort(answer.begin(), answer.end());
		for (auto e : answer)
			std::cout << e << "\n";
		std::cout << "\n";
	}
	return 0;
}