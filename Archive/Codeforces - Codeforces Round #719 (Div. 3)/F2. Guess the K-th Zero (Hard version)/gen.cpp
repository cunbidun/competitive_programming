#include <vector>

#include "../../Script/genlib.h"
#include "../../Script/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(0, 100);
  vector<int> a = gen_array(N, 0, 1, 0);
  a.push_back(0);
  shuffle(a.begin(), a.end());
  N++;
  int cnt;
  for (int i = 0; i < N; i++) {
    cnt += a[i] == 0;
  }
  int T = rnd.next(1, cnt);
  cout << N << ' ' << T << '\n';
  for (int i : a) {
    cout << i;
  }
  cout << '\n';
  for (int i = 0; i < T; i++) {
    cout << rnd.next(1, T - i) << ' ';
  }
  cout << '\n';
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
