/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll fact[100000];


void factorial(int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans % mod * i % mod) % mod;
        fact[i] = ans;
    }
}

ll mpow(ll a , ll b) {
    ll ans = 1;
    while (b > 0) {

        if (b % 2 == 1) {
            ans = (ans % mod * a % mod) % mod;
        }
        a = (a % mod * a % mod) % mod;
        b = b / 2;

    }
    return ans;

}


ll diff_combinations(int n , int k) {

    if (n == k) return 1;
    ll ans = fact[n];
    ll den = (fact[n - k] * fact[k]) % mod;
    return (ans * mpow(den, mod - 2)) % mod;


}



int countGoodSubsequences(string &s) {
    int n = s.size();

    ll ans = 0;

    factorial(n);
    vector<int> dp(26, 0);
    int maxi = 1;

    for (auto it : s) {
        dp[it - 'a'] += 1;
        maxi = max(maxi, dp[it - 'a']);
    }

    for (int i = 1; i <= maxi; i++) {
        ll temp_ans = 1;
        for (int k = 0; k < 26; k++) {

            if (dp[k] >= i) {
                temp_ans = temp_ans * (diff_combinations(dp[k], i) + 1);
                temp_ans = temp_ans % mod;

            }

        }

        ans = (ans + (temp_ans - 1)) % mod;

    }



    return ans % mod;

}






void Function() {


    string s;
    cin >> s;
    int ans = countGoodSubsequences(s);

    cout << "Ans " << ans << endl;





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