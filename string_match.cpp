#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

class string_match {
public:
  vector<int> is_match;
  vector<int> freq_cntA[26];
  vector<int> freq_cntB[26];
  int n ;
//  INITIALIZE AND CALCULATIONG PREFIX SUM
  void init(string & a , string & b) {
    n = a.size();
    is_match.assign(n, 0);
    for (int i = 0; i < 26; i++) {
      freq_cntA[i].assign(n, 0);
      freq_cntB[i].assign(n, 0);
    }

    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        is_match[i] = 1;
      }
      freq_cntA[a[i] - 'a'][i] = 1;
      freq_cntB[b[i] - 'a'][i] = 1;
    }

    for (int i = 1; i < n; i++) {

      is_match[i] += (i > 0 ? is_match[i - 1] : 0);
      for (int ch = 0; ch < 26; ch++) {
        freq_cntA[ch][i] += freq_cntA[ch][i - 1];
        freq_cntB[ch][i] += freq_cntB[ch][i - 1];
      }
    }

  }

//  CHECK IF TWO STRING FROM LEFT TO RIGHT ARE SAME OR NOT
  bool is_same(int l , int r) {
    if (l > r)return true;
    int prefix_sum = is_match[r] - (l > 0 ? is_match[l - 1] : 0);
    if (prefix_sum == (r - l + 1)) return true;
    return false;
  }

//  CHECK IS TWO STRING FROM LEFT TO RIGHT ARE SAME AFTER REARRANGEMENT
  bool is_same_rearrange(int l , int r ) {
    if (l > r) return true;

    for (int ch = 0; ch < 26; ch++) {

      int a_cnt = freq_cntA[ch][r] - (l > 0 ? freq_cntA[ch][l - 1] : 0);
      int b_cnt = freq_cntB[ch][r] - (l > 0 ? freq_cntB[ch][l - 1] : 0);

      if (a_cnt != b_cnt) return false;

    }
    return true;
  }

// CHECK TWO STRING ARE SAME AFTER SOME ARRANGEMENT FROM LEFT TO RIGHT

  bool query(int l , int r) {
    return is_same(0, l - 1) && is_same_rearrange(l, r) && is_same(r + 1, n - 1);
  }


  vector<int> prefix_A(int l , int r) {

    vector<int> pre(26);

    for (int ch = 0; ch < 26; ch++) {
      pre[ch] = freq_cntA[ch][r] - (l > 0 ? freq_cntA[ch][l - 1] : 0);
    }

    return pre;
  }
  vector<int> prefix_B(int l , int r) {

    vector<int> pre(26);

    for (int ch = 0; ch < 26; ch++) {
      pre[ch] = freq_cntB[ch][r] - (l > 0 ? freq_cntB[ch][l - 1] : 0);
    }

    return pre;
  }

//  check whether two string after rearangement(string a-> l1-r1 , and  strign b -> l2-r2 ) are same
  bool query_ans_ismatch(int l1, int r1 , int l2, int r2) {
    //  Case 1. when both the left and right query do not intersect
    if (r1 < l2) {
      if (is_same(0, l1 - 1) && is_same(r1 + 1, l2 - 1) && is_same(r2 + 1, n - 1) && is_same_rearrange(l1, r1) && is_same_rearrange(l2, r2)) {
        cout << " yes" << endl;
        return 1;
      }
      return 0;
    } else if (l1 > r2) {

      if (is_same(0, l2 - 1) && is_same(r2 + 1, l1 - 1) && is_same(r1 + 1, n - 1) && is_same_rearrange(l1, r1) && is_same_rearrange(l2, r2)) {
        return true;
      }
      return false;

    }

//  Case 2. when one. part is lies inside the other part
    if (l2 >= l1 && r2 <= r1) {

      if (is_same(0, l1 - 1) && is_same(r1 + 1, n - 1) && is_same_rearrange(l1, r1)) {

        return 1;
      }
      return 0;

    } else if (l1 >= l2 && r1 <= r2) {
      if (is_same(0, l2 - 1) && is_same(r2 + 1, n - 1) && is_same_rearrange(l2, r2)) {

        return 1;
      }
      return 0;
    }


// Case 3. when overlap
// case A
    if (l2 >= l1 && l2 <= r1) {

      vector<int> pre_A = prefix_A(l1, r1);
      vector<int> pre_B = prefix_B(l1, l2 - 1);

      for (int ch = 0; ch < 26; ch++) {
        if (pre_B[ch] > pre_A[ch]) {
          return 0;
        }
        else pre_A[ch] -= pre_B[ch];
      }


      vector<int> pre_C = prefix_A(r1 + 1, r2);
      vector<int> pre_D = prefix_B(l2, r2);



      for (int ch = 0; ch < 26; ch++) {
        if (pre_C[ch] > pre_D[ch]) {
          return 0;
        }
        else pre_D[ch] -= pre_C[ch];
      }

      if (pre_A == pre_D && is_same(0, l1 - 1) && is_same(r2 + 1, n - 1)) {
        return 1;
      } else {
        return 0;
      }




    }
// Case B
    else if (l1 >= l2 && l1 <= r2) {
      vector<int> pre_A = prefix_B(l2, r2);
      vector<int> pre_B = prefix_A(l2, l1 - 1);
      for (int ch = 0; ch < 26; ch++) {
        if (pre_B[ch] > pre_A[ch]) {
          return 0;
        }
        else pre_A[ch] -= pre_B[ch];
      }

      vector<int> pre_C = prefix_B(r2 + 1, r1);
      vector<int> pre_D = prefix_A(l1, r1);



      for (int ch = 0; ch < 26; ch++) {
        if (pre_C[ch] > pre_D[ch]) {
          return 0;
        }
        else pre_D[ch] -= pre_C[ch];
      }

      if (pre_A == pre_D && is_same(0, l2 - 1) && is_same(r1 + 1, n - 1)) {
        return 1;
      } else {
        return 0;
      }

    }


    return false;
  }




};


int main() {
#ifndef ONLINE_JUDGE
  // for getting input
  freopen("input1.txt", "r", stdin);
  // for writing output
  freopen("output1.txt", "w", stdout);
#endif

  string s;
  cin >> s;

// string b;
// cin >>b;

  string a, b;
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    a.push_back(s[i]);
  }
  for (int i = n / 2; i < n; i++) {
    b.push_back(s[i]);
  }



  reverse(b.begin(), b.end());

  int l1 , l2 , r1 , r2;
  cin >> l1 >> r1 >> l2 >> r2;
  l2 = (n - 1 - l2);
  r2 = (n - 1 - r2);
  swap(l2, r2);

  string_match str;
  str.init(a, b);
// cout<<l1<<" " << r1 <<" "<<l2 <<" "<<r2<<endl;
// cout<<"a "<<a<<" b "<<b<<endl;

  if (str.query_ans_ismatch(l1, r1, l2, r2)) {
    cout << "yes" << endl;
  } else {
    cout << " No" << endl;
  }

// cout<<a<<" b "<<b<<endl;












}

