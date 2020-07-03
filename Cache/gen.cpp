#include "bits/stdc++.h"

using namespace std;

ofstream out;
stringstream in;

string TextFileToString(string filename) {
  ostringstream dosString(ios::out | ios::binary); // *** binary
  ifstream inFile(filename.c_str());

  string line;
  while (getline(inFile, line))
    dosString << line << "\r\n";

  return dosString.str();
}

// get correct input format from rawInput
void get(string name) { in << TextFileToString(name); }

int ___solve();

int main(int argc, char *argv[]) {
  string name = string(argv[1]);
  get(name);
  out.open(name);
  out << in.str();
  out.close();
  if (argv[2][0] == 't') {
    name.pop_back();
    name.pop_back();
    name.pop_back();
    out.open(name + ".out");
    out << fixed << setprecision(10);
    ___solve();
    out.close();
  }
}
#define st first
#define nd second
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
long long s[2000005];
long long a[2000005];
long long ans[2000005];
long long mod = 1e9 + 7;

long long tru(long long t) {
  long long res = -t;
  while (res < 0)
    res += mod;
  res %= mod;
  return res;
}

int ___solve() {
  s[2] = 1;
  s[3] = 1;
  a[3] = 3;
  ans[3] = 1;
  for (int i = 4; i <= 2e6 + 1; i++) {
    s[i] = a[i - 1] % mod;
    a[i] = (s[i - 1] * 2 % mod + a[i - 1] % mod) % mod;
    ans[i] = (ans[i - 3] % mod + s[i - 1] % mod) % mod;
  }
  int t;
  in >> t;
  while (t--) {
    int n;
    in >> n;
    if (n < 3)
      out << 0 << endl;
    else
      out << (ans[n] * 4) % mod << endl;
  }
}
