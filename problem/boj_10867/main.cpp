// 10867. 중복 빼고 정렬하기
// https://www.acmicpc.net/problem/10867

// vector, algorithm 헤더를 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	vector<int> inputs;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		inputs.push_back(num);
	}

	sort(inputs.begin(), inputs.end());										// 정렬
	inputs.erase(unique(inputs.begin(), inputs.end()), inputs.end());		// 중복 제거

	for (const int& element : inputs)
		cout << element << " ";
	cout << "\n";

	return 0;
}