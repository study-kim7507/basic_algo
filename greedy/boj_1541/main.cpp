#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num[51];
char op[51];

int n_num = 0;
int n_op = 0;

void print()
{
	for (int i = 0; i < n_num; i++)
		cout << num[i] << " ";
	cout << "\n";
	
	for (int i = 0; i < n_op; i++)
		cout << op[i] << " ";
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	string tmp = "";
	int tmpSum = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != '-' && input[i] != '+')
			tmp += input[i];
		if (input[i] == '-')
		{
			tmpSum += stoi(tmp);
			num[n_num++] = tmpSum;
			
			tmpSum = 0;
			tmp = "";
			op[n_op++] = input[i];
		}
		else if (input[i] == '+')
		{
			tmpSum += stoi(tmp);
			tmp = "";
		}
		if (i == input.size() - 1)
		{
			if (tmpSum != 0)
			{
				tmpSum += stoi(tmp);
				num[n_num++] = tmpSum;
			}
			else
				num[n_num++] = stoi(tmp);
		}
	}

	// print();

	long long ans = num[0];
	for (int i = 1; i < n_num; i++)
		ans -= num[i];

	cout << ans << "\n";
	return 0;
}