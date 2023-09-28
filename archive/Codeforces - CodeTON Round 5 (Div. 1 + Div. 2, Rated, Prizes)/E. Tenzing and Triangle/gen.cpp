#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(1, 5);
  int K = rnd.next(5, 10);
  int A = rnd.next(1, 5);
  cout << N << ' ' << K << ' ' << A << '\n';
  set<array<int, 2>> s;
  for (int i = 0; i < N; i++) {
    while (true) {
      int x = rnd.next(0, K);
      int y = rnd.next(0, K);
      int c = rnd.next(1, 10);
      if (x + y < K && x < K && y < K && s.find({x, y}) == s.end()) {
        s.insert({x, y});
        cout << x << " " << y << " " << c << '\n';
        break;
      }
    }
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
