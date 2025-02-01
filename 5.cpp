/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int max_bit = 32;
int up[32][1000000];
void binary_lifting(vector<int> adj[], int node , vector<int> & vis, int par) {
    // cout << " Node " << node << endl;
    vis[node] = 1;
    up[0][node] = par;
    for (int j = 1; j < max_bit; j++) {

        int temp_val = up[j - 1][node];

        if (temp_val == -1) {
            up[j][node] = temp_val;
        } else {
            up[j][node] = up[j - 1][temp_val];
        }

    }
    for (auto it : adj[node]) {
        if (vis[it] == 1) continue;
        binary_lifting(adj, it, vis , node);
    }


}



int get_query(int node , int k) {

    for (int i = max_bit - 1; i >= 1; i--) {

        if ((k & (1 << i) ) > 0) {
            node = up[i - 1][node];
            if (node == -1) return -1;
        }

    }
    return node;
}





void Function() {

    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        v[i] = a;
    }

    vector<int> adj[n + 1];
    // for (auto it : v) cout << it << " "; cout << endl;

    for (int i = 0; i < n; i++) {
        adj[i].push_back(v[i]);
        // adj[v[i]].push_back(i);
    }
    vector<int> vis(n + 1, 0);
    //

    for (int i = 0; i < n; i++) {
        if (vis[v[i]] == 0) {
            binary_lifting(adj, v[i], vis, i);
        }
    }

    for (int i = 0; i < k; i++) {
        int a , b;
        cin >> a >> b;
        // cout << a << " B " << b << endl;
        a--;

        int ans = get_query(a, b);
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

    int t = 1;
// cin >>t;

    while (t--) {
        Function();
    }

}