#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

ofstream screen, res;
ifstream in;

void WA(int num = 0, string message = "") {
  res << "wrong answer\n";
  if (message != "") {
    res << message << endl;
  } else if (num == 1) {
    res << "too many questions" << endl;
  } else if (num == 2) {
    res << "incorrect format" << endl;
  }
}

void OK() { res << "accepted" << endl; }

void interactor() {
  int N, T;
  in >> N >> T;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    char c;
    in >> c;
    a[i] = c - '0';
  }

  cout << N << ' ' << T << endl;
  screen << "G" << N << ' ' << T << endl;

  int limit = 6e4;
  int q = 0;

  while (T--) {
    int K;
    in >> K;
    cout << K << endl;
    screen << "G" << K << endl;
    while (1) {
      string type;
      cin >> type;
      screen << type << " ";
      if (type == "!") {
        int ans;
        cin >> ans;
        screen << ans << endl;
        int cur, cnt = 0;
        for (int i = 1; i <= N; i++) {
          if (a[i] == 0) {
            cnt++;
          }
          if (cnt == K) {
            cur = i;
            break;
          }
        }
        if (cur != ans) {
          cout << -1 << endl;
          screen << "R" << -1 << endl;
          WA(0, "expected " + to_string(cur) + ", but got " + to_string(ans));
          return;
        }
        a[cur] = 1;
        break;
      } else {
        int l, r;
        cin >> l >> r;
        screen << l << " " << r << endl;
        q++;
        if (q > limit) {
          WA(1);
          return;
        }
        if (l < 1 || r < 1 || N < l || N < r) {
          WA(2);
          return;
        }
        int s = 0;
        for (int i = l; i <= r; i++) {
          s += a[i];
        }
        cout << s << endl;
        screen << 'G' << s << endl;
      }
    }
  }
  OK();
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
