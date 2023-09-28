#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = 100;
  cout << T << '\n';
  while (T--) {

    int N = rnd.next(4, 4);
    int M = rnd.next(4, 4);
    int Q = rnd.next(100, 100);

    cout << N << ' ' << M << ' ' << Q << '\n';

    gen_connected_graph(N, M);

    cout << '\n';
    while (Q--) {
      int l = rnd.next(1, N);
      int r = rnd.next(l, N);
      cout << l << ' ' << r << '\n';
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
