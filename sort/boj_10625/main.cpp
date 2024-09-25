#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

struct student
{
	string name;
	int scores[3];				// 국어, 영어 수학
};
vector<student> students;
bool cmp(const student& a, const student& b)
{
	if (a.scores[0] != b.scores[0]) return a.scores[0] > b.scores[0];
	else if (a.scores[1] != b.scores[1]) return a.scores[1] < b.scores[1];
	else if (a.scores[2] != b.scores[2]) return a.scores[2] > b.scores[2];

	for (int i = 0; i < (a.name.length() <= b.name.length() ? a.name.length() : b.name.length()); i++)
	{
		if (a.name[i] == b.name[i]) continue;
		return a.name[i] < b.name[i];
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--)
	{
		student s;
		cin >> s.name;
		for (int i = 0; i < 3; i++)
			cin >> s.scores[i];
	
		students.push_back(s);
	}

	sort(students.begin(), students.end(), cmp);

	for (const student& s : students)
		cout << s.name << "\n";

	return 0;
}