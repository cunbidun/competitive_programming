#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(5, 5);
  int M = rnd.next(7, 7);
  cout << N << ' ' << M << '\n';
  gen_weighted_graph(N, M, 1, 20);
  int K = rnd.next(1, N);
  int Q = rnd.next(1, 10);
  cout << K << ' ' << Q << '\n';
  while (Q--) {
    int a = rnd.next(1, N);
    int b = rnd.next(1, N);
    cout << a << ' ' << b << '\n';
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
