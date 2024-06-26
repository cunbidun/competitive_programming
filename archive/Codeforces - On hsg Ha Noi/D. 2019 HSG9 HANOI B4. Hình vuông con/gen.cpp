#include "genlib.h"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(2, 20);
  int M = rnd.next(2, 20);

  int K = rnd.next(1, min(M, N));
  cout << N << ' ' << M << ' ' << K << '\n';
  for (int i = 0; i < N; i++) {
    gen_array(M, 1, 10);
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
