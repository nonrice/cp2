#include <bits/stdc++.h>
using namespace std;

void solve(){
    pair<int, int> x{ 3, 5 };
    auto [a, b] = x;
    print("{} {}\n", a, b);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
