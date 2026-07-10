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

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    ll w; cin >> w;
    vector<ll> a(n);
    for (auto& x : a){
        cin >> x;
    }

    for (auto&& [i, h] : views::enumerate(a)){
        w -= h;
        if (w < 0){
            println("{}", i);
            return 0;
        }
    }

    println("{}", n);
}
