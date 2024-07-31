/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



template <typename T> void _print(vector<T> v) { for (auto it : v) { cout << it << " "; } cout << endl; }

template <typename T> void _print(vector<vector<T>> v) { for (auto it : v) { for (auto a : it) { cout << a << " "; } cout << endl; } }

template <typename T, typename T2> void _print(map<T, T2> mp) { for (auto it : mp) { cout << it.first << " " << it.second << endl; } }

template <typename T, typename T2> void _print(unordered_map<T, T2> mp) { for (auto it : mp) { cout << it.first << " " << it.second << endl; } }

template <typename T> void _print(set<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T> void _print(unordered_set<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T> void _print(multiset<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T, typename T2> void _print(vector<pair<T, T2>> v) { for (auto it : v) { cout << it.first << " " << it.second << endl; } }

template <typename T, typename T2> void _print(T2 n, vector<T> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (auto it : adj[i]) { cout << it << " "; } cout << endl; } }

template <typename T, typename T1> void _print(T n, vector<vector<T1>> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (const auto& it : adj[i]) { cout << "["; for (size_t j = 0; j < it.size(); ++j) { cout << it[j] << (j < it.size() - 1 ? "," : ""); } cout << "] "; } cout << "\n"; } }

template <typename T> void _print(T n, vector<pair<int, int>> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (const auto& p : adj[i]) { cout << "[" << p.first << "," << p.second << "] "; } cout << "\n"; } }

template <typename T , typename T1 , typename T2 , typename T3 , typename T4 > void _print(T a , T1 b , T2 c , T3 d , T4 e) { cout << a << " # " << b << " # " << c << " # " << d << " # " << e << endl;}

template <typename T , typename T1 , typename T2 , typename T3 > void _print(T a, T1 b , T2 c , T3 d) { cout << a << " # " << b << " # " << c << " # " << d << endl;}

template <typename T , typename T1 , typename T2 > void _print(T a , T1 b , T2 c) { cout << a << " # " << b << " # " << c << endl;}

template <typename T , typename T1 > void _print(T a, T1 b) { cout << a << " # " << b << endl;}

template <typename T > void _print(T a) { cout << a << endl;}



vector<int>  prefix(vector<int> & v , int sum) {

    int n = v.size();
    int low = 0;
    int high = 0;
    int total = 0;
    vector<int> dp(n, 0);
    while (high < n) {

        total += v[high];

        while (low <= high && total > sum) {
            dp[low] = high - low;
            total -= v[low];
            low++;
        }

        high++;


    }


    while (low < n) {
        dp[low] = high - low;
        low++;
    }

    // _print(dp);

    return dp;
}



void Function() {


    int n , k , s;
    cin >> n >> k >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp =  prefix(v, s);

    // _print(dp);

    int ans = 0;
    for (int i = 0; i < n; i++) {

        int start = i;

        for (int j = 0; j < k; j++) {

            start = start + dp[start];
            if (start >= n) {
                ans = max(ans, n - i);
                break;
            }



        }
        // _print(i, start);
        if (start <= n)
            ans = max(ans, start - i);


    }




    cout << ans << endl;



}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt", "r", stdin);
    // for writing output
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;

    while (t--) {
        Function();
    }

}