#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

ofstream screen, res;
ifstream in;

int limit = 4500;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void WA(int num = 1) {
  res << "wrong answer\n";
  if (num == 1) {
    res << "too many questions" << endl;
  } else if (num == 2) {
    res << "incorrect format" << endl;
  } else {
    res << "extra tokens" << endl;
  }
}

void OK() { res << "accepted\nusing " << 4500 - limit << " questions" << endl; }

void interactor() {
  long long n, p;
  int k;
  in >> n >> k >> p;
  cout << n << " " << k << endl;
  screen << "G" << n << " " << k << " (" << p << ")" << endl;
  while (limit--) {
    long long l, h;
    cin >> l >> h;
    screen << l << " " << h << endl;
    if (l < 1 || h < 1 || h < l || n < l || n < h) {
      WA(2);
      cout << "Bad" << endl;
      screen << "GBad" << endl;
      return;
    }
    if (l <= p && p <= h) {
      cout << "Yes" << endl;
      screen << "GYes" << endl;
      if (l == h) {
        OK();
        return;
      }
    } else {
      cout << "GNo" << endl;
      screen << "GNo" << endl;
    }
    // p += rng() % (2 * k + 1) - k;
    // p += rng() % (k + 1);
    p += k;
    p = max(1LL, p);
    p = min(p, n);
    screen << "G" << p << endl;
  }
  WA(1);
  cout << "Bad" << endl;
  screen << "GBad" << endl;
}

int main(int argc, char *argv[]) {
  char *que = "/tmp/que";
  char *ans = "/tmp/ans";
  mkfifo(que, 0777);
  mkfifo(ans, 0777);

  pid_t pid = fork();
  if (pid < 0) {
    return 1;
  }
  if (pid == 0) {
    int fd_read = open(ans, O_RDONLY);
    int fd_write = open(que, O_WRONLY);
    dup2(fd_read, 0);
    dup2(fd_write, 1);
    execl("solution", "solution", NULL);
  } else {
    int fd_write = open(ans, O_WRONLY);
    int fd_read = open(que, O_RDONLY);
    dup2(fd_read, 0);
    dup2(fd_write, 1);

    in.open(argv[1]);
    screen.open(argv[2]);
    res.open(argv[3]);

    interactor();

    in.close();
    screen.close();
    res.close();
  }
  unlink(que);
  unlink(ans);
  return 0;
}