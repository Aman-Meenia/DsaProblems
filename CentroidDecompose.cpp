/*
 Author: Aman Meenia
 Created: Sun Dec  8 13:16:38 IST 2024
 */
#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;

const int N = 200002;
int n, k;
int sz[N];
int cnt[N];
bool dead[N];
ll ans = 0;
int max_depth = 0;
vector<int> adj[N];

void subarray_size(int root, int parent) {
  sz[root] = 1;
  for (auto it : adj[root]) {
    if (it == parent || dead[it])
      continue;

    subarray_size(it, root);
    sz[root] += sz[it];
  }
}

int centroid_find(int root, int parent, int size) {

  for (auto it : adj[root]) {
    if (it == parent || dead[it])
      continue;
    if ((2 * sz[it]) > size) {
      return centroid_find(it, root, size);
    }
  }
  return root;
}

void dfs(int root, int parent, int depth, bool isCalculate) {

  if (depth > k)
    return;

  if (isCalculate) {
    ans += cnt[k - depth];
  } else {
    cnt[depth]++;
  }
  max_depth = max(depth, max_depth);

  for (auto it : adj[root]) {
    if (it == parent || dead[it])
      continue;
    dfs(it, root, depth + 1, isCalculate);
  }
}

void centroid_decompose(int root) {

  subarray_size(root, -1);

  int centroid = centroid_find(root, -1, sz[root]);
  dead[centroid] = true;
  cnt[0] = 1;
  max_depth = 0;

  for (auto it : adj[centroid]) {
    if (dead[it])
      continue;
    dfs(it, -1, 1, true);
    dfs(it, -1, 1, false);
  }
  fill(cnt, cnt + max_depth + 10, 0);
  for (auto it : adj[centroid]) {
    if (dead[it])
      continue;
    centroid_decompose(it);
  }
}

void Function() {
  cin >> n >> k;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  centroid_decompose(0);

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    Function();
  }
}
