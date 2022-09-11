#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(1, 10);
  int C = 100;
  int M = 10;
  cout << N << ' ' << C << ' ' << M << '\n';
  for (int i = 0; i < N; i++) {
    cout << rnd.next(1, 10) << ' ' << rnd.next(1, 10) << '\n';
  }
  for (int i = 0; i < M; i++) {
    cout << rnd.next(1, 1000000) << '\n';
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
