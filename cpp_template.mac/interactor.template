#include "interactive.hpp"
#include <iostream>

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
  int q_asked = 0;
  int LIMIT = 62;

  int bound = (1 << 30);

  int a, b;
  from_input >> a >> b;

  while (1) {
    char type;
    int c, d;
    from_sol >> type >> c >> d >> endl;
    q_asked++;
    if ((type != '?' && type != '!') || c < 0 || d < 0 || bound <= c ||
        bound <= d) {
      WA(2);
      break;
    }
    if (type == '?') {
      if (q_asked > LIMIT) {
        to_sol << -2;
        WA(1);
        break;
      }
      to_sol << sgn((a ^ c) - (b ^ d)) << endl;
    } else {
      if (a == c && b == d) {
        OK();
      } else {
        WA(0, "incorrect output");
      }
      break;
    }
  }
}

#include <sys/fcntl.h>

#include <fcntl.h>
#include <filesystem>
#include <sys/stat.h>
#include <unistd.h>

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
      res << "wrong answer" << endl;
      res << "solution exited unexpectedly (SIGPIPE) with code " << sig << endl;
      exit(0);
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
