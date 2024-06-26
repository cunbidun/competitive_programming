#include <bits/stdc++.h>

using namespace std;

class AssignPoints {
public:
  vector<int> assign(int N, vector<int> results) {
    vector<int> ans(N);
    vector<array<int, 2>> a;
    for (int i = 0; i < N; i++) {
      a.push_back({results[i], i});
    }
    sort(a.begin(), a.end());
    int cur = 0;
    int smaller = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (a[i][0] == -1) {
        continue;
      }
      if (a[i][0] > cur) {
        smaller += cnt;
        cnt = 0;
        cur = a[i][0];
      }
      cnt++;
      ans[a[i][1]] = N - smaller;
    }
    return ans;
  }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector<int> p1, bool hasAnswer,
                        vector<int> p2) {
  cout << "Test " << testNum << ": [" << p0 << ","
       << "{";
  for (int i = 0; int(p1.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p1[i];
  }
  cout << "}";
  cout << "]" << endl;
  AssignPoints *obj;
  vector<int> answer;
  obj = new AssignPoints();
  clock_t startTime = clock();
  answer = obj->assign(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds"
       << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t"
         << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p2[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t"
       << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p2.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p2[i]) {
          res = false;
        }
      }
    }
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
  vector<int> p1;
  vector<int> p2;

  {
    // ----- test 0 -----
    p0 = 5;
    int t1[] = {12, 20, 47, 15, 32};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {5, 3, 1, 4, 2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 4;
    int t1[] = {-1, -1, -1, -1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {0, 0, 0, 0};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 5;
    int t1[] = {-1, 14, -1, -1, 17};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {0, 5, 0, 0, 4};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 6;
    int t1[] = {14, 14, 17, 14, 17, 17};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {6, 6, 3, 6, 3, 3};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = 5;
    int t1[] = {28, 12, -1, 9, 12};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {2, 4, 0, 5, 4};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
