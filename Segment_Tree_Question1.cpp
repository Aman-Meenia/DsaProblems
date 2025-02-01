/*
 Author: Aman Meenia
 Created: Fri Jan 31 22:18:03 IST 2025
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->

class node {
public:
  int minimum_val;
  int index;

  node() {
    minimum_val = INT_MAX;
    index = -1;
  }
};

const int N = 100100;
node t[N];

node merge(node a, node b) {

  if (a.minimum_val == b.minimum_val) {
    if (a.index < b.index)
      return a;
    return b;
  }
  if (a.minimum_val < b.minimum_val)
    return a;
  return b;
}

#define mid (l + (r - l) / 2)
void build(int index, int l, int r) {

  if (l == r) {
    t[index].minimum_val = 0;
    t[index].index = l;
    return;
  }

  build(2 * index, l, mid);
  build(2 * index + 1, mid + 1, r);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int lq, int rq) {

  if (lq > r || rq < l)
    return;

  if (lq <= l && rq >= r) {
    t[index].minimum_val += 1;
    return;
  }

  update(2 * index, l, mid, lq, rq);
  update(2 * index + 1, mid + 1, r, lq, rq);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

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

void Function() {
  int k;
  cin >> k;
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  build(1, 0, k);

  for (int i = 0; i < n; i++) {

    node ans = get_query(1, 0, k, 0, v[i]);
    int index = ans.index;
    cout << " Index " << index << endl;
    update(1, 0, k, index, index);
  }
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    Function();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
