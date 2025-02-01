/*
 Author: Aman Meenia
 Created:
 */
#include <filesystem> // Required for filesystem in C++17
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem; // Alias for std::filesystem

// Function to find the longest palindrome and also print files
string longestPalindrome(string s) {
  // Print files in the current directory
  string path = "/Users/aman"; // Current directory
  cout << "Files in current directory: " << endl;
  for (const auto &entry :
       fs::directory_iterator(path)) { // Use 'fs' here for filesystem
    cout << entry.path().filename().string() << endl; // Print filenames
  }
  std::cout << "Current directory: " << fs::current_path() << std::endl;

  // Move to the parent directory
  fs::path parentPath = fs::current_path().parent_path();
  fs::current_path(parentPath);

  // Print the new current directory
  std::cout << "Moved to parent directory: " << fs::current_path() << std::endl;

  // Placeholder palindrome logic (you'll replace this with actual logic)
  return "bab";
}

int main() {
  string s;
  cout << "Enter a string: ";
  cin >> s;

  string ans = longestPalindrome(s);
  cout << "Longest palindrome: " << ans << endl;

  return 0;
}
