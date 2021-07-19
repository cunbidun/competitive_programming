#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int T = 1;
  cout << T << '\n';
  while (T--) {
    int N = rnd.next(2, 10);
    cout << N << '\n';
    vector<int> a = gen_array(N, 1, N, false);
    for (int i = 0; i < N; i++) {
      if (a[i] == i + 1) {
        if (a[i] == N) {
          a[i]--;
        } else {
          a[i]++;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      cout << a[i] << ' ';
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
