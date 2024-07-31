/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


ll fact[200100];
ll inv[200100];

ll mpow(ll a , ll b) {

    ll ans = 1;

    while (b > 0) {

        if (b % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        b = b / 2;
    }
    return ans;

}

void factorial(int n) {
    ll ans = 1;

    for (int i = 1; i <= n; i++) {
        ans = (ans % mod * i % mod) % mod;
        fact[i] = ans;
        inv[i] = mpow(ans, mod - 2);
    }
}


ll different_ways(ll  n , ll k) {
    if (n == k) return 1;
    ll ans = fact[n];
    ans = ((ans * inv[fact[n - k]]) % mod * inv[fact[k]]) % mod;
    return ans;

}


int sovle(vector<int> &t) {
    ll ans = 0;
    unordered_map<int, int> mp;

    for (auto it : t) {
        mp[it] += 1;
    }

    vector<int> v;

    for (auto it : mp) v.push_back(it.second);
    sort(v.begin(), v.end());
    int maxi = v.back();
    factorial(maxi);
    for (int i = 1; i <= maxi; i++) {
        ll temp_ans = 1;
        int index = lower_bound(v.begin(), v.end(), i) - v.begin();
        for (int k = index; k < v.size(); k++) {

            if (v[k] >= i) {
                temp_ans = temp_ans * (different_ways(v[k], i) + 1);
                temp_ans = temp_ans % mod;
            }
        }
        ans = (ans + temp_ans - 1 ) % mod;
    }

    return ans;
}


void Function() {



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