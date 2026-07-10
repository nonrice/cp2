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

    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    for (auto& [s, r] : a){
        cin >> s >> r;
    }

    vector<ll> t(n);
    for (auto& x : t){
        cin >> x;
    }

    constexpr auto cmp2 = [](const auto& u, const auto& v)->bool{
        return u.second < v.second;
    };
    ranges::sort(a, cmp2);
    ranges::sort(t);

    partial_sum(a.begin(), a.end(), a.begin(), [](const auto& u, const auto& v){
                    return pair<long, long>{
                            max(u.first, v.first),
                            v.second
                        };
                });

    debug(a);
    debug(t);

    ll ans = 0;
    int r=m-1;
    for (int i=n-1; i>=0; --i){
        while (r>=0 && a[r].second > t[i]){
            r -= 1;
        }
        if (r < 0){
            break;
        }

        ans += a[r].first;
    }

    println("{}", ans);
}
