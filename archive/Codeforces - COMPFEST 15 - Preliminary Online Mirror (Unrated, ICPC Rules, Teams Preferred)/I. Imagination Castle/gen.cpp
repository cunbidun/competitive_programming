#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(4, 10);
  int M = rnd.next(4, 10);
  int r = rnd.next(0, 10);
  set<array<int, 2>> s;
  for (int i = 0; i < r; i++) {
    int x = rnd.next(1, N);
    int y = rnd.next(1, M);
    if (x == 1 && y == 1) {
      continue;
    }
    s.insert({x, y});
  }
  cout << N << ' ' << M << ' ' << s.size() << '\n';
  for (auto [x, y] : s) {
    cout << x << ' ' << y << '\n';
  }
  char number_str[10];
  snprintf(number_str, 10, "%d", test);
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