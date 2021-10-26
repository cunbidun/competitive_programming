#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(10, 10);
  int R = rnd.next(3, 4);
  int Q = rnd.next(1, 10);
  cout << N << ' ' << R << ' ' << Q << '\n';
  vector<int> p = gen_tree_p_list(N, 1, false);
  cout << rnd.next(1, R) << '\n';
  for (int i = 0; i < N - 1; i++) {
    cout << p[i] << ' ' << rnd.next(1, R) << '\n';
  }
  while (Q--) {
    int r1 = rnd.next(1, R);
    int r2 = rnd.next(1, R);
    while (r2 == r1) {
      r2 = rnd.next(1, R);
    }
    cout << r1 << ' ' << r2 << '\n';
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
