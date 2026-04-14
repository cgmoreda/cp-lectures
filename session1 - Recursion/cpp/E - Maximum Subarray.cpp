#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v;

struct sub {
    int best, sum, pref, suf;
};

sub dope(int l,int r) {
    if (l == r) {
        return sub{
            v[l],
            v[l],
            v[l],
            v[l],
        };
    }
    int mid = (l + r) / 2;
    sub L = dope(l, mid);
    sub R = dope(mid + 1, r);
    sub ret;
    ret.sum = L.sum + R.sum;
    ret.best = max({
        L.best,
        R.best,
        L.suf + R.pref
    });
    ret.suf = max(R.suf, R.sum + L.suf);
    ret.pref = max(L.pref, L.sum + R.pref);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    v = vector<int>(n);
    for (auto &i: v)cin >> i;
    cout << dope(0, n - 1).best << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
