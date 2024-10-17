// 가장 많은 종류의 구슬의 개수 >= 나머지 종류 구슬들 개수의 총합 -> 가장 많은 종류의 구슬의 개수 - 나머지 종류 구슬들 개수의 총합
// 가장 많은 종류의 구슬의 개수 < 나머지 종류 구슬들 개수의 총합 
    // 모든 종류 구슬들 개수의 총합이 짝수이면 0
    // 모든 종류 구슬들 개수의 총합이 홀수이면 1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long sum;
int mx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(x, mx);
        sum += x;
    }

    if (mx >= sum-mx)
        cout << mx - (sum - mx) << "\n";
    else if (sum % 2 == 0)
        cout << 0 << "\n";
    else 
        cout << 1 << "\n";

    return 0;
}