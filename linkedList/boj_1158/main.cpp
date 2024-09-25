#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	list<int> l;

	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}

	auto cursor = l.begin();

	for (int i = 0; i < k - 1; i++)
	{
		cursor++;
	}
	vector<int> result;

	while (true)
	{
		result.push_back(*cursor);
		cursor = l.erase(cursor);
		if (l.empty()) break;
		for (int i = 0; i < k - 1; i++)
		{
			if (cursor == l.end()) cursor = l.begin();
			++cursor;
			if (cursor == l.end()) cursor = l.begin();
		}
	}

	cout << "<";
	for (int i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << ", ";
	}
	cout << result[result.size() - 1];
	cout << ">";
	return 0;
}