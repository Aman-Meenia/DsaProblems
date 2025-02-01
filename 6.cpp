/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node {
    int cnt;
    node() {
        cnt = 0;
    }
};



node t[4 * 1000010];


node merge(node a, node b) {
    node ans ;
    ans.cnt = a.cnt + b.cnt;

    return ans;
}



void build(int index , int l , int r , vector<int> & v , int k) {

    if (l == r) {

        if (v[l] >= k) {
            t[index].cnt = 1;
        } else {
            t[index].cnt = 0;
        }

        return ;
    }

    int mid = l + (r - l) / 2;
    build(2 * index, l, mid, v, k);
    build(2 * index + 1, mid + 1, r, v, k);
    t[index] =  merge(t[2 * index], t[2 * index + 1]);

}



node get_query(int index , int l , int r , int lq , int rq) {

    if (lq > r || rq < l) return node();


    if (lq <= l && rq >= r) return t[index];

    int mid = l + (r - l) / 2;

    node ans1 = get_query(2 * index, l, mid , lq , rq);
    node ans2 = get_query(2 * index + 1, mid + 1, r, lq , rq);
    return merge(ans1, ans2);


}



int N = 1000000;
vector<int> bestPrice(int n, vector<vector<int>> price, int k, int q, vector<vector<int>> queries) {

    vector<int> v(N, 0);
    for (auto it : price) {
        int a = it[0];
        int b = it[1];

        v[a] += 1;
        v[b + 1] -= 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
        v[i] = sum;
    }

    // for (auto it : v) {
    //     cout << it << " ";
    // } cout << endl;

    build(1, 0, N - 1, v, k);
    vector<int> ans;
    for (auto it : queries) {
        int start = it[0];
        int end = it[1];

        node temp_ans = get_query(1, 0, N - 1, start, end);
        ans.push_back(temp_ans.cnt);
    }
    for (auto it : ans) cout << it << " "; cout << endl;
    return ans;


}


void Function() {

    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int a , b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int k;
    cin >> k;
    int m ;
    cin >> m;
    vector<vector<int>> t;

    for (int i = 0; i < m; i++) {
        int a , b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    bestPrice(n, v, k, m, t);


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