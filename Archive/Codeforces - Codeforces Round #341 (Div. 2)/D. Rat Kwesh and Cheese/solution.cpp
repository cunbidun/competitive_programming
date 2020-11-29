#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

double x, y, z;
string s;
long double ans = -1000000000.0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> x >> y >> z;
  if (x > 1 || y > 1 || z > 1) {
    if (x > 1) {
      if ((z * log(y) + log(log(x))) > ans) {
        ans = z * log(y) + log(log(x));
        s = "x^y^z";
      }
      if ((y * log(z) + log(log(x))) > ans) {
        ans = y * log(z) + log(log(x));
        s = "x^z^y";
      }
      if ((log(z) + log(y) + log(log(x))) > ans) {
        ans = log(z) + log(y) + log(log(x));
        s = "(x^y)^z";
      }
    }

    if (y > 1) {
      if ((z * log(x) + log(log(y))) > ans) {
        ans = z * log(x) + log(log(y));
        s = "y^x^z";
      }
      if ((x * log(z) + log(log(y))) > ans) {
        ans = x * log(z) + log(log(y));
        s = "y^z^x";
      }
      if ((log(z) + log(x) + log(log(y))) > ans) {
        ans = log(z) + log(x) + log(log(y));
        s = "(y^x)^z";
      }
    }

    if (z > 1) {
      if ((y * log(x) + log(log(z))) > ans) {
        ans = y * log(x) + log(log(z));
        s = "z^x^y";
      }
      if ((x * log(y) + log(log(z))) > ans) {
        ans = x * log(y) + log(log(z));
        s = "z^y^x";
      }
      if ((log(y) + log(x) + log(log(z))) > ans) {
        ans = log(y) + log(x) + log(log(z));
        s = "(z^x)^y";
      }
    }
    cout << s << "\n";
  } else {
    if (log(x) * pow(y, z) > ans) {
      ans = log(x) * pow(y, z);
      s = "x^y^z";
    }
    if (log(x) * pow(z, y) > ans) {
      ans = log(x) * pow(z, y);
      s = "x^z^y";
    }
    if (log(x) * z * y > ans) {
      ans = log(x) * z * y;
      s = "(x^y)^z";
    }
    if (log(y) * pow(x, z) > ans) {
      ans = log(y) * pow(x, z);
      s = "y^x^z";
    }
    if (log(y) * pow(z, x) > ans) {
      ans = log(y) * pow(z, x);
      s = "y^z^x";
    }
    if (log(y) * z * x > ans) {
      ans = log(y) * z * x;
      s = "(y^x)^z";
    }
    if (log(z) * pow(x, y) > ans) {
      ans = log(z) * pow(x, y);
      s = "z^x^y";
    }
    if (log(z) * pow(y, x) > ans) {
      ans = log(z) * pow(y, x);
      s = "z^y^x";
    }
    if (log(z) * y * x > ans) {
      ans = log(z) * y * x;
      s = "(z^x)^y";
    }
    cout << s << "\n";
  }
}