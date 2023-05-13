#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int N = rnd.next(1, 10);
  int M = rnd.next(1, 10);
  cout << N << ' ' << M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x = rnd.next(10);
      if (x == 1) {
        cout << 'o';
      } else if (x <= 4) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << "\n";
  }
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
