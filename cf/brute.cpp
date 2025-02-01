/*
 Author: Aman Meenia
 Created: Sat Dec 28 20:04:56 IST 2024
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->
using pii = pair<int, int>;

struct node {

  ll sum;

  node() { sum = 0; }
};

node t[8 * 200100];

// merge

node merge(node a, node b) {
  node ans;

  ans.sum = max(a.sum, b.sum);
  return ans;
}

// build

void build(int id, int l, int r) {

  if (l == r) {

    t[id].sum = 0;
    return;
  }

  int mid = l + (r - l) / 2;

  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  t[id] = merge(t[2 * id], t[2 * id + 1]);
}

// update

void update(int id, int l, int r, int lq, int rq, int val) {

  if (lq > r || rq < l) {
    return;
  }
  if (l >= lq && r <= rq) {
    t[id].sum += val;
    return;
  }

  int mid = l + (r - l) / 2;
  update(2 * id, l, mid, lq, rq, val);
  update(2 * id + 1, mid + 1, r, lq, rq, val);
  t[id] = merge(t[2 * id], t[2 * id + 1]);
}

// get ans
node get_query(int id, int l, int r, int lq, int rq) {

  if (lq > r || rq < l) {

    node ans;
    ans.sum = -1;
    return ans;
  }
  if (l >= lq && r <= rq) {

    return t[id];
  }
  int mid = l + (r - l) / 2;

  node ans1 = get_query(2 * id, l, mid, lq, rq);
  node ans2 = get_query(2 * id + 1, mid + 1, r, lq, rq);

  return merge(ans1, ans2);
}

void Function() {

  int n;
  cin >> n;
  vector<pii> v;
  int N = 2 * n + 10;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back({l, r});
  }

  build(1, 0, 4 * N);
  for (int i = 0; i < n; i++) {
    int l = v[i].first, r = v[i].second;
    if (l == r) {
      // cout << " l " << l << " r " << r << '\n';
      update(1, 0, N - 1, l, r, -1);
    }
  }

  string s;

  // node ans = get_query(1, 1, N - 1, 1, 1);
  // cout << ans.sum << " Ans " << '\n';

  for (int i = 0; i < n; i++) {

    int l = v[i].first, r = v[i].second;
    if (l == r) {
      update(1, 0, N - 1, l, r, 1);
    }
    // cout << " l " << l << " r " << r << '\n';

    node ans = get_query(1, 0, N - 1, l, r);
    // cout << " ANs " << ans.sum << '\n';
    if (ans.sum >= 0) {
      s.pb(' 1');
    } else {
      s.pb('0');
    }
    if (l == r) {
      update(1, 0, N - 1, l, r, -1);
    }
  }
  cout << s << '\n';
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    Function();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
