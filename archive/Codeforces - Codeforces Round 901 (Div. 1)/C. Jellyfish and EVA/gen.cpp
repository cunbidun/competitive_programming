#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = 10;
  cout << T << '\n';
  while (T--) {

    int N = rnd.next(10, 10);
    int M = rnd.next(10, 15);
    cout << N << " " << M << '\n';
    gen_dag(N, M, 1, 1);
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
