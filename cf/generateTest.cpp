/*
 Author: Aman Meenia
 Created: Thu Dec 12 22:01:14 IST 2024
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;

// <------------------------------ START CODE --------------------->

int rand_number_generaor(int a, int b) {

  int num = a + rand() % (b - a + 1);

  return num;
}

void Function() {

  int mid_size_of_array = 1;
  int max_size_of_array = 10;

  srand(time(NULL));
  int size = rand_number_generaor(1, 10);
  cout << " size " << size << endl;

  int min_val = 1;
  int max_val = 100;
  vector<int> v;
  for (int testCase = 0; testCase < size; testCase++) {
    int val = rand_number_generaor(min_val, max_val);
    v.push_back(val);
  }

  for (auto it : v)
    cout << it << " ";
  cout << '\n';
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    Function();
  }
  return 0;
}
