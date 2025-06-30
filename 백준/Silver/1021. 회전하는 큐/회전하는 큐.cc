#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, m;
	deque<int> dq;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int ans = 0;
	while (m--) {
		int pos;
		cin >> pos;
		int frontLength;
		int backLength;
		for (frontLength = 0; ; frontLength++) {
			if (dq[frontLength] == pos) break;
		}

		backLength = dq.size() - (frontLength + 1);
		if (frontLength <= backLength) {
			while (dq.front() != pos) {
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			dq.pop_front();
		}
		else {
			while (dq.back() != pos) { 
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
			dq.pop_back();
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}