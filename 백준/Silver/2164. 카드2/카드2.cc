#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}
	cout << q.front() << "\n";
}