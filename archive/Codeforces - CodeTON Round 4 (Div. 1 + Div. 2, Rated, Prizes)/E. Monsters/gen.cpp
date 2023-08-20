#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = rnd.next(100, 100);
  cout << T << '\n';
  while (T--) {
    int N = rnd.next(10, 10);
    int M = rnd.next(N - 1, N + 4);
    cout << N << ' ' << M << '\n';
    gen_array(N, 0, N / 2);
    cout << '\n';
    gen_connected_graph(N, M);
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
