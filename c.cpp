/*
 Author: Aman Meenia
 Created: Thu Dec 12 22:01:14 IST 2024
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

ll calc_total_sum(int n) { return (n * (n + 1)) / 2; }

void Function() {

  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> prefix(n + 1);

  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + v[i];
  }

  // for (auto it : prefix)
  //   cout << it << " ";
  // cout << '\n';
  //
  // for (auto it : v)
  //   cout << it << " ";
  // cout << '\n';

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, u;
    cin >> l >> u;
    l--;

    // cout << " l " << l << " u " << u << '\n';
    int it = upper_bound(prefix.begin(), prefix.end(), prefix[l] + u) -
             prefix.begin();

    if (it == l + 1) {
      cout << it << " ";
      continue;
    }
    if (it == prefix.size()) {
      cout << it - 1 << " ";
      continue;
    }

    int extra = prefix[it] - prefix[l] - u;

    // case 1. By choosing extra

    int sum = calc_total_sum(u);
    int sum1 = calc_total_sum(extra - 1);
    int ans1 = sum - sum1;

    int ans2 = INT_MIN;

    // case 2. Choose one step previous
    if (it > 1) {
      int new_u = prefix[it - 1] - prefix[l];

      ans2 = calc_total_sum(u) - calc_total_sum(u - new_u);
    }

    if (ans1 > ans2)
      cout << it << " ";
    else
      cout << it - 1 << " ";
  }

  // 5 2 5 5 5 2 4 5 4 2

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
