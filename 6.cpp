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




struct node {
    int cnt;

    node() {
        cnt = 0;
    }


};


node t[4 * 100010];

// merge
node merge(node a , node b) {
    node ans;
    ans.cnt = a.cnt + b.cnt;
    return ans;
}
// no need of build because everyValue is zero initially

// update

#define mid l + (r-l)/2

void update(int index ,  int l , int r , int idx) {

    if (idx > r || idx < l) return;

    if (l == r) {
        t[index].cnt += 1;
        return ;
    }



    update(2 * index, l, mid, idx);
    update(2 * index + 1, mid + 1, r, idx);
    t[index] =   merge(t[2 * index], t[2 * index + 1]);


}

// get answer

node query(int index , int l , int r , int lq , int rq) {

    if (lq > r || rq < l) return node();

    if (lq <= l && rq >= r) {
        // cout << " INDEX " << t[index].cnt << endl;
        return t[index];

    }

    node ans1 = query(2 * index , l , mid , lq , rq);
    node ans2 = query(2 * index + 1, mid + 1, r , lq , rq);
    return merge(ans1, ans2);

}



// Path Compression


map<int, int> mp;
int pathCompression(vector<int> & v ) {
    set<int> st;
    for (auto it : v) st.insert(it);
    int cnt = 0;
    for (auto it : st) {
        mp[it] = cnt;
        cnt++;
    }
    return cnt;
}

int getValue(int val) {
    return mp[val];
}





void Function() {


    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }




    vector<int> pre;

    pre.push_back(0);
    pre.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        pre.push_back(v[i] + pre.back());
    }
    // _print(v);
    // _print(pre);


// This give number of subarray with sum less Than or equal to K
    int k = 100;
    vector<int> t;
    for (int i = 0; i <= n; i++) {
        t.push_back(pre[i]);
        t.push_back(pre[i] - k);
    }

    int N =  pathCompression(t);
    int Ans = 0;
    for (int i = 0; i <= n; i++) {
        int startVal =  pre[i] - k;
        int endVal = N;
        startVal = getValue(startVal);

        int idx = getValue(pre[i]);
        // cout << " start " << startVal << " endVal " << endVal << " idx " << idx << endl;

        node ans =   query(1, 0, N, startVal, endVal);
        Ans += ans.cnt;

        update(1, 0, N, idx);

    }
    cout << "Ans " << Ans << endl;


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