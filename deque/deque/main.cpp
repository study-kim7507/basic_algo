// 양방향 큐, Deque
// 기존의 큐는 맨 앞에서 원소를 제거, 맨 뒤에서 원소를 삽입
// 덱은 맨 앞, 맨 뒤 모두에서 원소를 제거하고 삽입하는 것이 가능
#include <iostream>
#include <deque>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x)
{
	dat[--head] = x;
}

void push_back(int x)
{
	dat[tail++] = x;
}

void pop_front()
{
	head++;
}

void pop_back()
{
	tail--;
}

int front()
{
	return dat[head];
}

int back()
{
	return dat[tail - 1];
}

int main()
{
	deque<int> dq;
	dq.push_front(10); // 10
	dq.push_back(50); // 10 50
	dq.push_front(24); // 24 10 50
	
	// STL deque는 원소 순회가 가능
	for (int x : dq)
	{
		cout << x << " ";
	}
	cout << "\n";

	cout << dq.size() << "\n";
	dq.pop_front(); // 10 50
	dq.pop_back(); // 10
	cout << dq.back() << "\n"; // 10
	dq.push_back(72); // 10 72
	cout << dq.front() << "\n"; // 10
	dq.push_back(12); // 10 72 12
	dq[2] = 17; // 10 72 17
	dq.insert(dq.begin() + 1, 33); // 10 33 72 17
	dq.insert(dq.begin() + 4, 60); // 10 33 72 17 60
	
	for (int x : dq)
	{
		cout << x << " ";
	}
	cout << "\n";

	dq.erase(dq.begin() + 3); // 10 33 17 60
	cout << dq[3] << "\n"; // 60
	dq.clear();

	return 0;
}