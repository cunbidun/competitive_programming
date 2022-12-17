#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int T = 100;
  cout << T << endl;
  while (T--) {
    int N = rnd.next(1, 10);
    cout << N << endl;
    vector<int> a;
    for (int i = 1; i <= N; i++) {
      a.push_back(i);
    }
    shuffle(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
      cout << a[i] << " ";
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
