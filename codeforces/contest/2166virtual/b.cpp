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
    ll a, b, n;
    cin >> a >> b >> n;

    cout << 1 + (b*n > a && a != b) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
	    solve();
	}
}
