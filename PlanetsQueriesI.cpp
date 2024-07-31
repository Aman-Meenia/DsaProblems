/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

const int maxBit = 31;



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


void binary_lifting(vector<int> & v , vector<vector<int>> & up) {

    int n = v.size();

    for (int i = 0; i < n; i++) {
        up[0][i] = v[i];
    }

    for (int j = 1; j < maxBit; j++) {

        for (int i = 0; i < n; i++) {

            up[j][i] = up[j - 1][up[j - 1][i]];

        }

    }



}


int query_ans(int &node , int &k , vector<vector<int>> & up) {


    for (int i = maxBit - 1; i >= 0; i--) {

        if (k & (1 << i)) {

            node = up[i][node];
        }
    }
    return node;


}




void Function() {

    int n , k;
    cin >> n >> k;
    vector<int> v;
    vector<vector<int>> up( maxBit, vector<int> (n + 1, -1));
    for (int i = 0; i < n; i++) {
        int a ;
        cin >> a;
        a--;

        v.push_back(a);

    }


    binary_lifting(v, up);


    for (int i = 0; i < k; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        int ans = query_ans(a, b, up);
        cout << ans + 1 << endl;

    }

}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt", "r", stdin);
    // for writing output
    freopen("output1.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t = 1;
// cin >>t;

    while (t--) {
        Function();
    }

}