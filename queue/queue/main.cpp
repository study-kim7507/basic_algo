#include <iostream>
#include <queue>
using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
	dat[tail++] = x;
}

void pop()
{
	head++;
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
	queue<int> q;
	q.push(10); // 10
	q.push(20); // 10 20
	q.push(30); // 10 20 30
	cout << q.size() << "\n"; // 3
	if (q.empty()) cout << "Queue is empty!" << "\n";
	else cout << "Queue is not empty!" << "\n";

	q.pop(); // 20 30
	cout << q.front() << "\n"; // 20
	cout << q.back() << "\n"; // 30
	q.push(40); // 20 30 40
	cout << q.back() << "\n"; // 40
	
	return 0;
}