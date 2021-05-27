#include <bits/stdc++.h>

using namespace std;

string encrypt(string words) {
  words.erase(remove(words.begin(), words.end(), ' '), words.end());
  int n = words.size();
  int m = sqrt(n);
  int sz1 = -1, sz2 = -1;
  if (m * m >= n) {
    sz1 = m;
    sz2 = m;
  } else if (m * (m + 1) >= n) {
    sz1 = m;
    sz2 = m + 1;
  } else {
    sz1 = m + 1;
    sz2 = m + 1;
  }
  string ans = "";
  for (int i = 0; i < sz2; i++) {
    for (int j = i; j < n; j += sz2) {
      ans += words[j];
    }
    ans += " ";
  }
  return ans;
}

int main() {
  string words;
  getline(cin, words);

  string result = encrypt(words);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}