#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  cout << 1 << '\n';
  int R = rnd.next(5, 5);
  int C = rnd.next(5, 5);
  cout << R << ' ' << C << '\n';
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cout << rnd.next(1, 100) << ' ';
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
