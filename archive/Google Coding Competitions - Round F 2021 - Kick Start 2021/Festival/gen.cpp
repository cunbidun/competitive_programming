#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = 1;
  cout << T << '\n';
  while (T--) {
    int D = rnd.next(1, 10);
    int N = rnd.next(1, 5);
    int K = rnd.next(1, N);
    cout << D << ' ' << N << ' ' << K << '\n';
    for (int i = 0; i < N; i++) {
      int h = rnd.next(1, 10);
      int s = rnd.next(1, D);
      int e = rnd.next(s, D);
      cout << h << ' ' << s << ' ' << e << '\n';
    }
    cout << '\n';
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
