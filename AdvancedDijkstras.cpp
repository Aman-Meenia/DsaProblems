/*
 Author: Aman Meenia
 Created:
 CSES Problem Set Investigatio
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






void Function() {

    int n , m;
    cin >> n >> m;
    vector<vector<int> > adj[n];
    for (int i = 0; i < m; i++) {
        int a , b , c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }
// _print(n,adj);



    priority_queue<pair<ll, ll> , vector<pair<ll, ll>> , greater<pair<ll, ll>> > pq;

    vector<ll> price(n, LLONG_MAX);
    vector<ll> diffRoutes(n, 0);
    vector<ll> min_price(n, LLONG_MAX);
    vector<ll> max_price(n, LLONG_MIN);

    price[0] = 0;
    diffRoutes[0] = 1;
    pq.push({0, 0});
    min_price[0] = 0;
    max_price[0] = 0;

    while (!pq.empty()) {

        ll dist = pq.top().first;
        ll node = pq.top().second;
        pq.pop();


        if (dist > price[node]) continue;

        for (auto it : adj[node]) {
            ll u = it[0];

            ll d = it[1];


            if (d + dist > price[u]) continue;

            if (d + dist == price[u]) {
                diffRoutes[u] += diffRoutes[node];
                diffRoutes[u] %= mod;
                min_price[u] = min(min_price[u], min_price[node] + 1);
                max_price[u] = max(max_price[u], max_price[node] + 1);
            }
            if (d + dist < price[u]) {
                price[u] = d + dist;
                diffRoutes[u] = diffRoutes[node];
                min_price[u] = min_price[node] + 1;
                max_price[u] = max_price[node] + 1;
                pq.push({price[u], u});
            }

        }









    }


    cout << price[n - 1] << " " << diffRoutes[n - 1] % mod << " " << min_price[n - 1] << " " << max_price[n - 1] << endl;




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