#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<int> adj[], int node, vector<int> &vis, stack<int> &st) {
  vis[node] = 1;
  for (auto it : adj[node]) {
    if (vis[it] == 1)
      continue;

    dfs(adj, it, vis, st);
  }
  st.push(node);
}

// if want to print the node of every components than just add in vector while
// reaversing the the second dfs

void dfs2(vector<int> adj[], int node, vector<int> &vis) {
  vis[node] = 1;
  cout << node << " ";
  for (auto it : adj[node]) {
    if (vis[it] == 1)
      continue;

    dfs2(adj, it, vis);
  }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &v)

{
  int n = V;
  vector<int> adj[n];

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      adj[i].push_back(v[i][j]);
    }
  }

  vector<int> vis(n, 0);
  stack<int> st;

  // Step 1. Find the vertices according to the exit time

  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      dfs(adj, i, vis, st);
    }
  }

  // Step 2. reverse the edges

  vector<int> adj2[n];

  for (int i = 0; i < n; i++) {
    vis[i] = 0;
    for (auto it : adj[i]) {
      adj2[it].push_back(i);
    }
  }

  //  Step 3. again do dfs to find the different SCC
  // cout << " Start " << endl;
  // while (!st.empty()) {
  //   cout << st.top() << endl;
  //   st.pop();
  // }
  cout << " END " << endl;

  int differentComponents = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (vis[node] == 0) {
      dfs2(adj2, node, vis);
      differentComponents++;
      cout << endl;
    }
  }
  return differentComponents;
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   // for getting input
  //   freopen("input1.txt", "r", stdin);
  //   // for writing output
  //   freopen("output1.txt", "w", stdout);
  // #endif

  int n;
  cin >> n;
  int m;
  cin >> m;

  vector<vector<int>> v(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
  }

  int ans = kosaraju(n, v);
  cout << ans << endl;
}
