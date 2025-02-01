// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand_number_generaor(int a, int b) {

  int num = a + rand() % (b - a + 1);

  return num;
}

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  int mid_size_of_array = 1;
  int max_size_of_array = 10;

  int size = rand_number_generaor(1, 10);
  cout << size << endl;

  int min_val = 1;
  int max_val = 10;
  vector<int> v;
  for (int testCase = 0; testCase < size; testCase++) {
    int val = rand_number_generaor(min_val, max_val);
    v.push_back(val);
  }

  for (auto it : v)
    cout << it << " ";
  cout << '\n';

  // int n = rand_number_generaor(2, 10);
  // printf("%d\n", n);
  // set<int> used;
  // for (int i = 0; i < n; ++i) {
  //   int x;
  //   do {
  //     x = rand_number_generaor(1, 10);
  //   } while (used.count(x));
  //   printf("%d ", x);
  //   used.insert(x);
  // }
  // puts("");
}
