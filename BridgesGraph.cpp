/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



int Time[1000000];
int low[1000000];
vector<vector<int> > ans;
void criticalBridges(vector<int> adj[] , int root , vector<int> & vis , int cnt , int parent) {

	vis[root] = 1;
	cnt += 1;

	Time[root] = cnt;
	low[root] = cnt;
	for (auto it : adj[root]) {

		if (it == parent) continue;
		if (vis[it] == 0) {

			criticalBridges(adj, it, vis, cnt, root);
			low[root] = min(low[root], low[it]);
			// when not able to reach
			if (low[it] > Time[root]) {
				ans.push_back({root, it});
			}
		} else {

// if already visited choose low as min of low ,
			low[root] = min(low[root], low[it]);

		}




	}


}


void Function() {

	int n ;
	cin >> n;

	vector<int> adj[n];

	for (int  i = 0; i < n; i++) {
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}


	vector<int> vis(n, 0);
	criticalBridges(adj, 0, vis, 0, -1);

	for (auto it : ans) cout << it[0] << " " << it[1] << endl;

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