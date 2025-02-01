/*
 Author: Aman Meenia
 Created: Mon Sep 30 10:10:51 IST 2024
 */
#include <bits/stdc++.h>
#include <ctime>
#define ll long long
#define mod 1000000007
using namespace std;

#define N 100010

int Low[N];
int Time[N];
vector<vector<int>> ans;
void criticalBridges(vector<int> adj[], int root, int parent, vector<int> &vis,
                     int time) {

  vis[root] = 1;
  Low[root] = time;
  Time[root] = time;

  for (auto it : adj[root]) {

    if (it == parent)
      continue;

    if (vis[it] == 0) {

      criticalBridges(adj, it, root, vis, time + 1);
      Low[root] = min(Low[root], Low[it]);
      if (Low[it] > Time[root]) {
        ans.push_back({root, it});
      }

    } else {
      Low[root] = min(Low[root], Low[it]);
    }
  }
}

void Function() {
  int n;
  cin >> n;
  vector<int> adj[n + 1];
  int m;
  cin >> m;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  vector<int> vis(n + 1, 0);

  criticalBridges(adj, 0, -1, vis, 1);

  cout << "ANs.size() " << ans.size() << endl;
  for (auto it : ans) {
    for (auto a : it) {
      cout << a << " ";
    }
    cout << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    Function();
  }
}

