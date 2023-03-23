#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int N = 2e5;
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    if (i < N / 2) {
      cout << "ab" << '\n';
    } else {
      cout << "a\n";
    }
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
