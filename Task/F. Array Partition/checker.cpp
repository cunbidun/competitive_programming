#include "bits/stdc++.h"

using namespace std;

string text_file_to_string(string filename) {
  ostringstream dosString(ios::out | ios::binary); // *** binary
  ifstream inFile(filename.c_str());

  string line;
  while (getline(inFile, line)) {
    dosString << line << "\r\n";
  }

  return dosString.str();
}

string remove_space(string s) {
  s.erase(remove(s.begin(), s.end(), '\n'), s.end());
  s.erase(remove(s.begin(), s.end(), '\t'), s.end());
  s.erase(remove(s.begin(), s.end(), '\r'), s.end());
  s.erase(remove(s.begin(), s.end(), ' '), s.end());
  return s;
}

bool token_checker(string ex, string ac) { return remove_space(ex) == remove_space(ac); }

bool double_compare(double ex, double ac, double esp) {
  double minv = min(ex * (1.0 - esp), ex * (1.0 + esp));
  double maxv = max(ex * (1.0 - esp), ex * (1.0 + esp));
  return abs(ex - ac) <= esp || (minv <= ac + 1E-15 && ac <= maxv + 1E-15);
}

pair<bool, double> double_checker(string expected, string actual, double e) {
  vector<double> expected_token, actual_token;
  stringstream ex(expected), ac(actual);
  double tmp;
  while (ex >> tmp) {
    expected_token.push_back(tmp);
  }
  while (ac >> tmp) {
    actual_token.push_back(tmp);
  }
  if (expected_token.size() != actual_token.size()) {
    return {0, -1};
  }
  double maxDiff = 0.0;
  for (int i = 0; i < expected_token.size(); i++) {
    maxDiff = max(maxDiff, abs(expected_token[i] - actual_token[i]));
    if (!double_compare(expected_token[i], actual_token[i], e)) {
      return {0, maxDiff};
    }
  }
  return {1, maxDiff};
}

// edit this method to check
// check without expected output
bool check(stringstream &in, stringstream &out) { return true; }

// check with expected output
int a[100];
bool check(stringstream &in, stringstream &ac, stringstream &ex) {
  string v1, v2;
  ac >> v1;
  ex >> v2;
  if (v1 != v2) {
    return 0;
  }
  if (v1 == "NO") {
    return 1;
  }
  int x, y, z;
  ac >> x >> y >> z;
  int n;
  in >> n >> n;
  for (int i = 1; i <= n; i++) {
    in >> a[i];
  }
  int mx1 = 0, mx2 = 0;
  int mn = 1000000000;
  for (int i = 1; i <= x; i++) {
    mx1 = max(mx1, a[i]);
  }
  for (int i = x + 1; i <= x + y; i++) {
    mn = min(mn, a[i]);
  }
  for (int i = x + y + 1; i <= n; i++) {
    mx2 = max(mx2, a[i]);
  }
  if (mx1 == mx2 && mx1 == mn) {
    return 1;
  } else {
    cout << "wrong answer\n";
    cout << mx1 << " " << mn << " " << mx2 << "\n";
    return 0;
  }
}

int main(int argc, char *argv[]) {
  // don't have checker parameters
  if (argc == 4) {
    if (string(argv[2]) == "") {
      stringstream in, out;
      in << text_file_to_string(string(argv[1]));
      out << text_file_to_string(string(argv[3]));
      if (check(in, out)) {
        cout << "accepted\n";
      } else {
        cout << "wrong answer\n";
      }
    } else {
      stringstream in, ex, ac;
      in << text_file_to_string(string(argv[1]));
      ex << text_file_to_string(string(argv[2]));
      ac << text_file_to_string(string(argv[3]));
      if (check(in, ac, ex)) {
        cout << "accepted\n";
      }
    }
  }

  // don't have double checker parameters
  if (argc == 5) {
    stringstream in;
    in << text_file_to_string(string(argv[1]));

    if (string(argv[2]) == "") {
      stringstream out;
      out << text_file_to_string(string(argv[3]));
      if (check(in, out)) {
        cout << "accepted\n";
      } else {
        cout << "wrong answer\n";
      }
    } else {
      // Double checker
      if (string(argv[4])[0] == 'D') {
        double e = 1.0 / pow(10, string(argv[4])[1] - '0');
        stringstream ex, ac;
        ex << text_file_to_string(string(argv[2]));
        ac << text_file_to_string(string(argv[3]));
        pair<bool, double> res = double_checker(ex.str(), ac.str(), e);
        if (res.first) {
          cout << "accepted\nMaximal difference is " << res.second << "\n";
        } else {
          if (res.second == -1) {
            cout << "wrong answer\nDifference in number of tokens";
          } else {
            cout << "wrong answer\nMaximal difference is " << res.second << ", which is exceed "
                 << e << "\n";
          }
        }
      } else {
        // normal token checker
        stringstream in, ex, ac;
        in << text_file_to_string(string(argv[1]));
        ex << text_file_to_string(string(argv[2]));
        ac << text_file_to_string(string(argv[3]));
        if (token_checker(ex.str(), ac.str())) {
          cout << "accepted\n";
        } else {
          cout << "wrong answer\n";
        }
      }
    }
  }
}