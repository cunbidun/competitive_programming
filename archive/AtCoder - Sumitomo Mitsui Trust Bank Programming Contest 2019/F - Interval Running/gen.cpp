#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int limit = 10;
  int T1 = rnd.next(1, limit);
  int T2 = rnd.next(1, limit);
  int A1 = rnd.next(1, limit);
  int A2 = rnd.next(1, limit);
  int B1 = rnd.next(1, limit);
  int B2 = rnd.next(1, limit);

  while (B1 == A1) {
    B1 = rnd.next(1, limit);
  }
  while (B2 == A2) {
    B2 = rnd.next(1, limit);
  }
  cout << T1 << ' ' << T2 << '\n';
  cout << A1 << ' ' << A2 << '\n';
  cout << B1 << ' ' << B2 << '\n';
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
