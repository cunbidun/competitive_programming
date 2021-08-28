#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = 1000;
  cout << T << '\n';
  while (T--) {
    int N = rnd.next(1, 10);
    vector<int> a = rnd.perm(N);
    vector<int> b = rnd.perm(N + 1);
    cout << 2 * N + 1 << '\n';
    for (int i = 0; i < N; i++) {
      cout << b[i] * 2 + 1 << ' ' << a[i] * 2 + 2 << ' ';
    }
    cout << b[N] * 2 + 1;
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
