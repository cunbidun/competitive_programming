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
}int a[105];
int ___solve() {
  int n, cp, m = 0, d, nt = 0;
  in >> n;
  in >> cp;
  for (int i = 1; i <= n; i++) {
    in >> a[i];
  }

  if (a[cp] == 1) {
    nt = nt + 1;
  }
  for (int i = 1; i <= cp - 1; i++) {
    if (a[cp - i] == 1 && a[cp + i] == 1) {
      nt = nt + 2;
    }
    if (a[cp + i] == 1 && cp - i <= 0) {
      nt = nt + 1;
    }
    if (a[cp - i] == 1 && cp + i > n) {
      nt = nt + 1;
    }
  }
  d = 2 * cp;
  if (cp + cp - 1 < n) {
    for (int i = d; i <= n; i++) {
      if (a[i] == 1) {
        nt = nt + 1;
      }
    }
  }
  out << nt;
}
