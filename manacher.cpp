/*
 Author: Aman Meenia
 Created: Wed Sep 11 10:34:32 IST 2024
 */
// #include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;

class manachers {
public:
  string generateString(string &s) {
    cout << " S " << s << endl;
    int n = s.size();
    string ans;

    ans.push_back('#');
    for (auto it : s) {
      ans.push_back(it);

      ans.push_back('#');
    }
    cout << " Ans " << ans << endl;
    return ans;
  }

  vector<int> dp;
  void manachersAlgorithm(string &s) {

    int n = s.size();

    dp.assign(n, 1);

    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++) {
      int t = l + r - i;
      t = max(t, 0);
      dp[i] = max(0, min(r - i, dp[t]));
      while (i + dp[i] < n && i - dp[i] >= 0 && s[i + dp[i]] == s[i - dp[i]]) {
        dp[i]++;
      }
      if (i + dp[i] > r) {
        r = i + dp[i];
        l = i - dp[i];
      }
    }

    for (auto it : dp)
      cout << it << " ";
    cout << endl;
  }

  bool isPalindromeLtoR(int l, int r) {

    int mid = (l + r) / 2;
    int cnt = r - l + 1;
    // it means same partiy and size of the subarray is odd
    if (l % 2 == r % 2) {
      int index = mid * 2 + 1;
      if (dp[index] >= cnt)
        return true;
    } else {
      int index = mid * 2 + 1;
      index += 1;
      if (dp[index] >= cnt)
        return true;
    }
    cout << " FALSE " << endl;
    return false;
  }
};

class Solution {
public:
  int minCut(string &s) {

    int ans = 0;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    manachers *m = new manachers();

    string t = m->generateString(s);
    m->manachersAlgorithm(t);

    if (m->isPalindromeLtoR(0, n - 1)) {
      cout << " True " << endl;
      return 0;
    }
    for (int i = 1; i < n; i++) {
      dp[i] = 1 + dp[i - 1];
      if (m->isPalindromeLtoR(0, i))
        dp[i] = 1;
      for (int j = 1; j <= i; j++) {
        if (m->isPalindromeLtoR(j, i)) {
          for (int tt = j; tt <= i; tt++)
            cout << s[tt];
          cout << endl;
          dp[i] = min(dp[i], dp[j - 1] + 1);
        }
      }
    }
    cout << " Dp array " << endl;
    for (auto it : dp)
      cout << it << " ";
    cout << endl;

    return dp[n - 1] - 1;
  }
} m;

void Function() {

  string s;
  cin >> s;

  Solution *S = new Solution();
  int Ans = S->minCut(s);
  cout << " Ans " << Ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    Function();
  }
}
