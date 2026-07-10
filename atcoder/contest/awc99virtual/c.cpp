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

    int n, q; cin >> n >> q;
    vi p(n-1);
    for (auto& x : p){
        cin >> x;
        x -= 1;
    }
    vector<pair<long, long>> ops(q);
    for (auto& [x, d] : ops){
        cin >> x >> d;
        x -= 1;
    }

    vector<vi> adj(n);
    for (auto&& [i, u] : views::enumerate(p)){
        adj[u].push_back(i+1);
    }
    vector<ll> ch(n);
    for (auto& [x, d] : ops){
        ch[x] += d;
    }

    vector<ll> ans(n);
    auto dfs = [&](this auto self, int u)->void{
        static ll cur = 0;

        cur += ch[u];
        ans[u] = cur;
        for (auto v : adj[u]){
            self(v);
        }
        cur -= ch[u];
    };

    dfs(0);

    for (auto x : ans){
        print("{} ", x);
    }
    println();
}
