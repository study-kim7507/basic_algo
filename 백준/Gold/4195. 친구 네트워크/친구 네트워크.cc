// BOJ 4195. 친구 네트워크
#include <iostream>
#include <unordered_map>
#include <iostream>
#include <unordered_map>
using namespace std;

int parent[200001];
int sz[200001];

int uf_find(int x) {
    if (x != parent[x]) return parent[x] = uf_find(parent[x]);
    return parent[x];
}

int uf_union(int x, int y) {
    x = uf_find(x);
    y = uf_find(y);

    if (x != y) {
        parent[y] = x;
        sz[x] += sz[y];
    }
    return sz[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int f;
        cin >> f;

        unordered_map<string, int> mp;
        int idx = 0;

        for (int i = 0; i < 200001; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        while (f--) {
            string a, b;
            cin >> a >> b;

            if (!mp.count(a)) mp[a] = idx++;
            if (!mp.count(b)) mp[b] = idx++;

            cout << uf_union(mp[a], mp[b]) << "\n";
        }
    }
    return 0;
}
