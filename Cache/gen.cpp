#include "bits/stdc++.h"

using namespace std;

ofstream out;
stringstream in;

string text_file_to_string(string filename) {
  ostringstream dosString(ios::out | ios::binary); // *** binary
  ifstream inFile(filename.c_str());
  string line;
  while (getline(inFile, line)) {
    dosString << line << "\r\n";
  }
  return dosString.str();
}

// get correct input format from rawInput
void get(string name) { in << text_file_to_string(name); }

int ___solve(){};

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