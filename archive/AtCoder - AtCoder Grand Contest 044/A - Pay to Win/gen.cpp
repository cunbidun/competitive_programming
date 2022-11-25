#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int T = 1000;
  cout << T << endl;
  while (T--) {
    // long long N = rnd.next((long long)1e17, (long long)1e18);
    // int A = rnd.next(1, (int)1e9);
    // int B = rnd.next(1, (int)1e9);
    // int C = rnd.next(1, (int)1e9);
    // int D = rnd.next(1, (int)1e9);
    long long N = rnd.next((long long)1, (long long)1e6);
    int A = rnd.next(1, (int)10);
    int B = rnd.next(1, (int)10);
    int C = rnd.next(1, (int)10);
    int D = rnd.next(1, (int)10);
    cout << N << " " << A << " " << B << " " << C << " " << D << endl;
  }

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
