#include "interactive.hpp"
#include <iostream>
#include <random>
using namespace std;

int sgn(int a) { return (a > 0) - (0 > a); }

/**
 * @param from_input: The input stream from gen.cpp text file.
 *                    This file either passed from test case input or gen.cpp
 * @param screen: The output stream to text file that eventually print to screen
 */
void interactor(ifstream &from_input, ofstream &screen) {
  dual_in from_sol(cin, screen);
  dual_out to_sol(cout, screen);

  auto count_1 = [](string val) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
      cnt += val[i] == '1';
    }
    return cnt;
  };

  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

  int T = 1;
  to_sol << T << endl;
  while (T--) {
    int q_asked = 0;
    int LIMIT = 300;

    string val = "";
    for (int i = 0; i < 8; i++) {
      val += char('0' + rng() % 2);
    }
    string init = val;
    string V;
    while (1) {
      from_sol >> V >> endl;
      q_asked++;
      if (q_asked > LIMIT) {
        to_sol << -1;
        string msg = "Asked to much questions on test " + to_string(100 - T + 1);
        WA(1, msg);
        break;
      }

      int r = rng() % 8;
      string W = "00000000";
      for (int i = 0; i < 8; i++) {
        W[(i + r) % 8] = V[i];
      }

      for (int i = 0; i < 8; i++) {
        if (val[i] == W[i]) {
          val[i] = '0';
        } else {
          val[i] = '1';
        }
      }
      int cnt = count_1(val);
      to_sol << cnt << '\n';
      if (cnt == 0) {
        break;
      }
    }
  }
  OK();
}

#include <sys/fcntl.h>

#include <fcntl.h>
#include <filesystem>
#include <sys/stat.h>
#include <unistd.h>

/**
 * The interactor program for interactive task.
 * The program should accept 3 file path as arguments and can be invoke this way:
 *
 *    interactor <input_file> <screen_file> <result_file>
 *
 * The input_file will contain data that will be feed into interactor
 *
 * The screen_file will store interaction between solution and the interactor.
 * Later, this data will be print to screen.
 *
 * The result_file will contain the result of the test.
 * Later, this data will be use to report error and verdict.
 */
int main(int argc, char *argv[]) {
  filesystem::path tmp_dir = filesystem::temp_directory_path();
  char const *que = "/tmp/que";
  char const *ans = "/tmp/ans";
  mkfifo(que, 0777), mkfifo(ans, 0777);
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
    ofstream screen;
    ifstream in;
    in.open(argv[1]);
    screen.open(argv[2]);
    res.open(argv[3]);
    assert(argc == 4);
    signal(SIGPIPE, [](int sig) {
      res << "solution exited unexpectedly (SIGPIPE) with code " << sig << endl;
      exit(1);
    });
    int fd_write = open(ans, O_WRONLY);
    int fd_read = open(que, O_RDONLY);
    dup2(fd_read, 0);
    dup2(fd_write, 1);
    interactor(in, screen);
    in.close();
    screen.close();
    res.close();
  }
  unlink(que);
  unlink(ans);
  return 0;
}
