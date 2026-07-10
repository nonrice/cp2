#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    for (auto& x : a){
        cin >> x;
    }
    string s; cin >> s;

    int l=-1, r=n;
    for (auto c : s){
        if (c == 'L'){
            l += 1;
        } else {
            r -= 1;
        }
    }


    vi ans(n);
    int p = 1;
    for (auto&& [i, c] : views::enumerate(s | views::reverse)){
        if (c == 'L'){
            p = (p * a[l]) % m;
            l -= 1;
        } else {
            p = (p * a[r]) % m;
            r += 1;
        }

        ans[i] = p;
    }

    for (auto x : ans | views::reverse){
        print("{} ", x);
    }
    println();
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
	    solve();
	}
}
