#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define mid (l + (r - l) / 2)

struct node {
  int cnt;
  node() { cnt = 0; }
};

// Declare

node t[4 * 200100];

// merge
node merge(node a, node b) {
  node ans;

  ans.cnt = a.cnt + b.cnt;
  return ans;
}

// update

void update(int index, int l, int r, int lq, int rq) {
  if (lq > r || rq < l) {
    return;
  }

  if (lq <= l && rq >= r) {

    t[index].cnt = 1;
    return;
  }

  update(2 * index, l, mid, lq, rq);
  update(2 * index + 1, mid + 1, r, lq, rq);

  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

// get query

node get_query(int index, int l, int r, int lq, int rq) {

  if (lq > r || rq < l)
    return node();

  if (lq <= l && rq >= r) {
    return t[index];
  }

  node ans1 = get_query(2 * index, l, mid, lq, rq);
  node ans2 = get_query(2 * index + 1, mid + 1, r, lq, rq);

  return merge(ans1, ans2);
}

#undef mid

static int cmp(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }
int main() {

  int n, m, m1;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<int>> q;

  cin >> m >> m1;
  for (int i = 0; i < m; i++) {
    int l, r, k;
    cin >> l >> r;
    k = l - 1;
    q.push_back({l, r, k, i});
  }

  sort(q.begin(), q.end(), cmp);

  // for(auto it:q){
  // 	cout<<it[0]<<" # "<<it[1]<<" # "<<it[2]<<" # "<<it[3]<<endl;
  // }

  vector<vector<int>> dp;
  map<int, int> mp;

  for (int i = 0; i < v.size(); i++) {
    if (mp.find(v[i]) != mp.end()) {
      dp.push_back({mp[v[i]], i});
    } else {
      dp.push_back({-1, i});
    }
    mp[v[i]] = i;
  }

  sort(dp.begin(), dp.end());

  // for (auto it : dp) {
  //   cout << it[0] << " # " << it[1] << endl;
  // }
  // cout << endl;

  // Now we find the number of element less than K

  int index = 0;
  vector<int> ANS(m);
  for (int i = 0; i < m; i++) {

    int l = q[i][0];
    int r = q[i][1];
    int k = q[i][2];
    int idx = q[i][3];

    while (index < n && dp[index][0] <= k) {
      int indexis = dp[index][1];
      // cout << "  Update      " << endl;
      update(1, 0, n - 1, indexis, indexis);
      index++;
    }

    node ans = get_query(1, 0, n - 1, l, r);
    ANS[idx] = ans.cnt;
    // cout << " ANS " << ans.cnt << endl;
  }

  for (auto it : ANS)
    cout << it << " ";
  cout << endl;
}
