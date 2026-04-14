#include<bits/stdc++.h>
using namespace std;
#define int long long
string x;
int n;

void dope(int open = 0, int closed = 0) {
    if (open < closed)return;
    if (open > n)return;
    if (x.size() == 2 * n) {
        if (open == closed) {
            cout << x << "\n";
        }
        return;
    }
    x += '(';
    dope(open + 1, closed);
    x.pop_back();
    x += ')';
    dope(open, closed + 1);
    x.pop_back();
}

void solve() {
    cin >> n;
    dope();
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
