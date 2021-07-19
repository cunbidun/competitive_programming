#ifndef _cps_interactive_h_
#define _cps_interactive_h_

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

ofstream screen, res;
ifstream in;

class dual_out {
public:
  dual_out(ostream &os1, ostream &os2) : os1(os1), os2(os2) {}
  template <class T>
  dual_out &operator<<(const T &x) {
    os1 << x;
    os2 << "\033[0;32m" << x << "\033[0m"; // green color
    return *this;
  }

  dual_out &operator<<(ostream &(*f)(ostream &)) {
    f(os1);
    f(os2);
    return *this;
  }

private:
  ostream &os1;
  ostream &os2;
};

class dual_in {
public:
  dual_in(istream &is, ostream &os) : is(is), os(os) {}

  template <class T>
  dual_in &operator>>(T &x) {
    is >> x;
    os << x << ' ';
    return *this;
  }

  dual_in &operator>>(ostream &(*f)(ostream &)) {
    f(os);
    return *this;
  }

private:
  istream &is;
  ostream &os;
};

/**
 * print wrong answer and exit 
 *
 * @param: num = 1, print "too many questions"
 * @param: num = 2, print "incorrect format"
 * @param: message, print if non-empty
 */
void WA(int num = 0, string message = "") {
  res << "wrong answer\n";
  if (message != "") {
    res << message;
  } else if (num == 1) {
    res << "too many questions";
  } else if (num == 2) {
    res << "incorrect format";
  } else if (num == 3) {
    res << "idleness limit exceeded";
  }
  exit(0);
}

void OK() {
  res << "accepted" << endl;
  exit(0);
}

#endif
