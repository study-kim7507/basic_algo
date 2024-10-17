#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n;
int result[1001];
deque<int> idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        idx.push_back(i);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            idx.push_back(idx.front());
            idx.pop_front();
        }
        result[idx.front()] = i;
        idx.pop_front();
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << " ";
    return 0;
}