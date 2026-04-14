#include<bits/stdc++.h>
using namespace std;
#define int long long
string x;
int n;
vector<vector<int> > children;
int rec(int person) {
    int ret = 0;
    for (auto i: children[person]) {
        ret += rec(i) + 1;
    }
    return ret;
}

void solve() {
    cin >> n;
    children = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (~parent)
            children[parent].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cout << rec(i) << " ";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
