#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  freopen(argv[1], "r", stdin);
  string line;
  while (getline(cin, line)) {
    if (line[0] == 'G') {
      cout << "\033[1;32m" << line.substr(1) << "\033[0m\n";
    } else if (line[0] == 'R') {
      cout << "\033[1;31m" << line.substr(1) << "\033[0m\n";
    } else {
      cout << line << "\n";
    }
  }
}