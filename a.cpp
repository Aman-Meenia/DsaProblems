/*
 Author: Aman Meenia
 Created: Sat Dec 21 23:51:20 IST 2024
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including
// tree_order_statistics_node_update
#include <iostream>

// #include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
// using namespace __gnu_pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->

void Function() {

  int n;
  cin >> n;
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
