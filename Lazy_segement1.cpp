/*
 Author: Aman Meenia
 Created: Sat Dec 14 17:33:14 IST 2024
 */
#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->
const int N = 100100;
class node {
public:
  int cnt;
  int ans1; // for 1
  int ans2; // for 0

  node() {
    cnt = 0;
    ans1 = 0;
    ans2 = 0;
  }
};

node t[4 * N];

void reset_segment_tree(int size) {
  for (int i = 0; i < size; i++) {
    t[i] = node();
  }
}

node merge(node &a, node &b) {

  node ans;
  ans.ans1 = ((a.cnt % 2 == 0) ? a.ans1 : a.ans2) ^
             ((b.cnt % 2 == 0) ? b.ans1 : b.ans2);
  ans.ans2 = ((a.cnt % 2 == 0) ? a.ans2 : a.ans1) ^
             ((b.cnt % 2 == 0) ? b.ans2 : b.ans1);

  return ans;
}

void lazy(int index, int l, int r) {

  if (l != r) {
    t[index * 2].cnt += t[index].cnt;
    t[index * 2 + 1].cnt += t[index].cnt;
  }

  if (t[index].cnt % 2 == 1) {
    swap(t[index].ans1, t[index].ans2);
  }
  t[index].cnt = 0;
}

#define mid (l + (r - l) / 2)
void build(int index, int l, int r, vector<int> &v, string &s) {

  if (l == r) {
    if (s[l] == '1') {
      t[index].ans1 = v[l];
    } else {
      t[index].ans2 = v[l];
    }
    return;
  }
  build(2 * index, l, mid, v, s);
  build(2 * index + 1, mid + 1, r, v, s);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int lq, int rq) {

  lazy(index, l, r);

  if (lq > r || rq < l)
    return;

  if (lq <= l && rq >= r) {
    t[index].cnt += 1;
    lazy(index, l, r);
    return;
  }

  update(2 * index, l, mid, lq, rq);
  update(2 * index + 1, mid + 1, r, lq, rq);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node get_query(int index, int l, int r, int lq, int rq) {
  lazy(index, l, r);
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
void Function() {

  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;

  string s;
  cin >> s;

  reset_segment_tree(4 * n);
  build(1, 0, n - 1, v, s);

  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {

    int type;
    cin >> type;

    if (type == 1) {
      int lq, rq;
      cin >> lq >> rq;
      lq--, rq--;
      update(1, 0, n - 1, lq, rq);

    } else {
      int ans_type;
      cin >> ans_type;

      node ans = get_query(1, 0, n - 1, 0, n - 1);
      if (ans_type == 1) {

        cout << ans.ans1 << ' ';
      } else {
        cout << ans.ans2 << ' ';
      }
    }
  }
  cout << '\n';
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
