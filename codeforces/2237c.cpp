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
    int n; cin >> n;
    vi a(n);
    for (auto& x : a){
        cin >> x;
    }

    long long r = a[0];
    for (int i=1; i<n; i++){
        if (r <= a[i]){
            r = a[i];
        } else {
            r += a[i];
        }
    }

    println("{}", r);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
	    solve();
	}
}
