/*
 Author: Aman Meenia
 Created: Sat Dec 28 18:18:43 IST 2024
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->

void Function() {

  int n, K;
  cin >> n >> K;

  string s;
  cin >> s;

  function<int(int, int)> fun = [&](int i, int k) -> int {
    vector<int> dp(26, 0);
    int start = i;
    int second_post = k - 1 - i;
    while (i < n) {
      dp[s[i] - 'a'] += 1;
      if ((i + second_post) != i)
        dp[s[i + second_post] - 'a'] += 1;
      i += K;
    }

    int cnt = 0;
    for (auto it : dp)
      cnt = max(cnt, it);
    return cnt;
  };
  int ans = 0;
  int k = K / 2;
  if (K % 2 == 0)
    k -= 1;
  for (int i = 0; i <= k; i++) {
    ans += fun(i, K - i);
  }
  cout << n - ans << "\n";
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    Function();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
