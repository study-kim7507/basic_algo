#include <iostream>
using namespace std;

int main()
{
	int result[26] = { 0 };
	string input;
	cin >> input;

	for (char a : input)
	{
		result[a - 'a']++;
	}

	for (int i : result)
	{
		cout << i << " ";
	}
	return 0;
}