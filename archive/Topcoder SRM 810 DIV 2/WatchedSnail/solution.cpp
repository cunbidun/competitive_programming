#include <bits/stdc++.h>

using namespace std;

template <class c>
struct rge { c b, e; };
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c>
  debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

class WatchedSnail {
public:
  double maxDistance(int raceTime, int c, int t, int d) {
    if (raceTime == t) {
      return d;
    }
    raceTime -= t;
    int r = raceTime - raceTime / t * t + t;
    raceTime = raceTime / t * t;

    int f = raceTime / t * 2;
    if (r != t) {
      f += 2;
    }
    f = min(f, c);
    return f * d;
  }
};

bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
  cout << "]" << endl;
  WatchedSnail *obj;
  double answer;
  obj = new WatchedSnail();
  clock_t startTime = clock();
  answer = obj->maxDistance(p0, p1, p2, p3);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p4 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
  if (hasAnswer) {
    res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
  }
  if (!res) {
    cout << "DOESN'T MATCH!!!!" << endl;
  } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
    cout << "FAIL the timeout" << endl;
    res = false;
  } else if (hasAnswer) {
    cout << "Match :-)" << endl;
  } else {
    cout << "OK, but is it right?" << endl;
  }
  cout << "" << endl;
  return res;
}
int main() {
  bool all_right;
  all_right = true;

  int p0;
  int p1;
  int p2;
  int p3;
  double p4;

  {
    // ----- test 0 -----
    p0 = 100;
    p1 = 3;
    p2 = 100;
    p3 = 47;
    p4 = 47.0;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 100;
    p1 = 10;
    p2 = 10;
    p3 = 47;
    p4 = 470.0;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 100;
    p1 = 8;
    p2 = 20;
    p3 = 47;
    p4 = 376.0;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 100;
    p1 = 2;
    p2 = 74;
    p3 = 47;
    p4 = 94.0;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
  {
    // ----- test 4 -----
    p0 = 60;
    p1 = 47;
    p2 = 10;
    p3 = 10;
    p4 = 100;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
  {
    // ----- test 5 -----
    p0 = 8;
    p1 = 9;
    p2 = 1;
    p3 = 940;
    p4 = 8460;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
  {
    // ----- test 5 -----
    p0 = 8;
    p1 = 10;
    p2 = 6;
    p3 = 264;
    p4 = 528;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
  if (all_right) {
    cout << "You're a stud (at least on the example cases)!" << endl;
  } else {
    cout << "Some of the test cases had errors." << endl;
  }
  return 0;
}
// END KAWIGIEDIT TESTING
