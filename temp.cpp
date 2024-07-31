/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
// #define mod 1000000007
using namespace std;
int mod = 1e9 + 7;

long long binexp(int a, int b, int m) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b = (b >> 1);
    }
    return ans;
}
long long fac(int n, int mod) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (i % mod * dp[i - 1] % mod) % mod;
    }
    return dp[n];
}

long long ncr(int n, int r) {
    if (n < r)
        return 0;
    if (n == r)
        return 1;
    long long fac_n = fac(n, mod);
    long long fac_r = fac(r, mod);
    long long fac_nr = fac(n - r, mod);
    long long inv_r = binexp(fac_r, mod - 2, mod);
    long long inv_nr = binexp(fac_nr, mod - 2, mod);
    return (fac_n * inv_nr * inv_r) % mod;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solve(vector<int> &A) {
    map<int, int> m;
    vector<pair<int, int>> v;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        m[A[i]]++;
    }
    for (auto it : m) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
    long long res = 0;
    for (int f = 1; f <= n; f++) {
        long long ans = 1;
        for (auto it : v) {
            if (it.second < f - 1) {
                break;
            }
            ans = (ans % mod * (ncr(it.second, f) + 1) % mod) % mod;
        }
        res += ans - 1;
    }
    return res;
}

void Function() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (auto it : v) cout << it << " "; cout << endl;

    int ans = solve(v);

    cout << " ANS " << ans << endl;


}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt", "r", stdin);
    // for writing output
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
// cin >>t;

    while (t--) {
        Function();
    }

}