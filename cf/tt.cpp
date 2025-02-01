/*
 Author: Aman Meenia
 Created: Sun Dec 15 08:29:18 IST 2024
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->
const int N = 500010;
int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

class node {
public:
  int val;

  node() { val = 0; }
};

node t[4 * N];

node merge(node &a, node &b) {

  node ans;

  ans.val = gcd(a.val, b.val);

  return ans;
}

#define mid (l + (r - l) / 2)

void build(int index, int l, int r, vector<int> &v) {

  if (l == r) {
    t[index].val = v[l];
    return;
  }

  build(2 * index, l, mid, v);
  build(2 * index + 1, mid + 1, r, v);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int lq, int rq, int new_val) {

  if (lq > r || rq < l)
    return;

  if (lq <= l && rq >= r) {
    t[index].val = new_val;
    return;
  }

  update(2 * index, l, mid, lq, rq, new_val);
  update(2 * index + 1, mid + 1, r, lq, rq, new_val);
  t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node get_query(int index, int l, int r, int lq, int rq, int guess) {

  if (lq > r || rq < l)
    return node();

  if (lq <= l && rq >= r) {
    if (t[index] % guess != 0) {
      return r - l + 1;
    }
    return t[index];
  }

  node ans1 = get_query(2 * index, l, mid, lq, rq, guess);
  node ans2 = get_query(2 * index + 1, mid + 1, r, lq, rq, guess);
  return merge(ans1, ans2);
}

void Function() {

  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  build(1, 0, n - 1, v);

  int t;
  cin >> t;

  for (int q = 0; q < t; q++) {

    int type;
    cin >> type;

    if (type == 1) {

      int l, r, guess;
      cin >> l >> r >> guess;
      l--, r--;

      node ans = get_query(1, 0, n - 1, l, r, guess);

      if (ans.val == guess) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }

    } else {
      int index, temp;
      cin >> index >> temp;
      update(1, 0, n - 1, index, index, temp, x);
    }
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
