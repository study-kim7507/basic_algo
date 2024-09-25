#include <iostream>
#include <stack>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
	dat[pos++] = x;
}

void pop()
{
	pos--;
}

int top()
{
	return dat[pos - 1];
}

int main()
{
	stack<int> s;
	s.push(5); // 5
	s.push(1); // 1 5
	s.push(3); // 3 1 5
	s.pop(); // 1 5
	cout << s.top() << "\n"; // 1

	return 0;
}