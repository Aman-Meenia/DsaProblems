/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int dp[1000100];

int fun(vector<int> & v , int index) {
    // cout << " index " << index << endl;
    if (index > v.size()) {
        return 1e7;
    }
    if (index == v.size()) return 0;
    if (dp[index] != -1) return dp[index];
// if choose  move to v[i]+index;
    int ans1 =  fun(v, index + v[index] + 1);

    // not choose
    int ans2 = 1 + fun(v, index + 1);
    return dp[index] = min(ans1, ans2);

}



void Function() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);

    int ans = fun(v, 0);
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