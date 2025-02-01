// generating a random sequence of string
#include <bits/stdc++.h>
using namespace std;

int rand_number_generaor(int a, int b) {

  int num = a + rand() % (b - a + 1);

  return num;
}

int main(int argc, char *argv[]) {

  srand(stoi(argv[1])); // atoi(s) converts an array of chars to int

  int min_size = 1; // SIZE OF STRING
  int max_size = 100;

  int size = rand_number_generaor(min_size, max_size);
  cout << size << endl;

  int min_val = 1; // CHARACTER RANGE
  int max_val = 26;

  string s;
  int idx = 0;
  for (int testCase = 0; testCase < size; testCase++) {
    // if (testCase == 0)  // When want to prin the string with same character
    idx = rand_number_generaor(min_val, max_val);
    char val = 'a' + idx - 1;
    s.push_back(val);
  }
  cout << s << '\n';
}
