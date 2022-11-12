#include "genlib.hpp"
#include "testlib.h"
#include <set>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int H = rnd.next(1, 5);
  int W = rnd.next(1, 5);
  auto X = gen_array(5, 1, H, false);
  auto Y = gen_array(5, 1, W, false);
  set<array<int, 2>> s;
  s.insert({1, 1});
  cout << H << ' ' << W << '\n';
  vector<array<int, 2>> arr;
  for (int i = 0; i < (int)X.size(); i++) {
    if (s.find({X[i], Y[i]}) == s.end()) {
      arr.push_back({X[i], Y[i]});
      s.insert({X[i], Y[i]});
    }
  }
  cout << arr.size() << '\n';
  for (auto [x, y] : arr) {
    cout << x << ' ' << y << '\n';
  }
  char number_str[10];
  sprintf(number_str, "%d", test);
  std::rename(number_str, ('S' + to_string(test) + ".in").c_str());
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int NUM_TEST = opt<int>(2);
  for (int i = 0; i < NUM_TEST; i++) {
    writeTest(i);
  }
  return 0;
}
