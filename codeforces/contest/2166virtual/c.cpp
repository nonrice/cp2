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
    list<int> a;
    for (int i=0; i<n; i++){
	int x; cin >> x;
	a.push_back(x);
    }
    
    vector<list<int>::iterator> p(n);
    ranges::iota(p, a.begin());
    ranges::sort(p, [&](auto a, auto b){
		return *a < *b;
	    });

    ll ans = 0;
    for (auto it : p | views::take(n-1)){
	int l = (it == a.begin()) ? *a.rbegin() : *prev(it);
	int r = (it == prev(a.end())) ? *a.begin() : *next(it);

	ans += min(l, r);
	a.erase(it);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
	    solve();
	}
}
