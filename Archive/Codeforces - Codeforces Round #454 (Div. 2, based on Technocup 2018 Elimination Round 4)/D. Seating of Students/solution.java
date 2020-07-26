import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task907D solver = new Task907D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task907D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            if (n == 1 && m == 1) {
                out.println("YES");
                out.println(1);
                return;
            }
            if (n == 3 && m == 3) {
                out.println("YES");
                out.println("2 4 6");
                out.println("8 3 7");
                out.println("1 9 5");
                return;
            }
            if (n == 4 && m == 1) {
                out.println("YES");
                out.println("3");
                out.println("1");
                out.println("4");
                out.println("2");
                return;
            }
            if (n < 4 && m < 4) {
                out.println("NO");
                return;
            }

            out.println("YES");

            if (m == 1) {
                int cur = 1;
                for (int i = 1; i <= n; i++) {
                    out.println(cur);
                    cur += 2;
                    if (cur > n) cur = 2;

                }
                return;
            }
            if (m == 3) {
                int cur = 1;
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        out.print(cur + " ");
                        cur += 2;
                        if (cur > n * m) cur = 2;
                    }
                    out.println("");
                }
                return;
            }
            if (m == 2) {
                ArrayList<Integer> l1 = new ArrayList<>();
                ArrayList<Integer> l2 = new ArrayList<>();
                int cur = 1;
                boolean f = true;

                for (int i = 1; i <= n; i++) {
                    l1.add(cur);
                    if (f) {
                        cur += 3;
                        f = false;
                    } else {
                        cur += 1;
                        f = true;
                    }
                    if (cur > 2 * n) {
                        break;
                    }
                }
                cur = 2;
                f = true;
                for (int i = 1; i <= n; i++) {
                    l2.add(cur);
                    if (f) {
                        cur += 1;
                        f = false;
                    } else {
                        cur += 3;
                        f = true;
                    }
                    if (cur > 2 * n) {
                        break;
                    }
                }
                int pos = l1.size() - 1;
                f = true;
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= 2; j++) {
                        if (f) {
                            out.print(l1.get(pos) + " ");
                            pos--;
                            if (pos == -1) {
                                f = false;
                                pos = l2.size() - 1;
                            }
                        } else {
                            out.print(l2.get(pos) + " ");
                            pos--;
                        }
                    }
                    out.println("");
                }
                return;
            }
            if (m % 2 == 0) {
                int[][] ans = new int[n + 1][m + 1];
                int cur = 1;
                int sum = 1 + m;
                for (int i = 1; i <= n; i++) {
                    if (i % 2 == 1) {
                        int l = m / 2;
                        int r = l + 1;
                        boolean f = true;
                        while (l != 0) {
                            if (f) {
                                ans[i][l] = cur;
                                ans[i][r] = sum - cur;
                                f = false;
                            } else {
                                ans[i][l] = sum - cur;
                                ans[i][r] = cur;
                                f = true;
                            }
                            cur++;
                            l--;
                            r++;
                        }
                        cur += m / 2;

                    } else {
                        int l = m / 2;
                        int r = l + 1;
                        boolean f = true;
                        while (l != 0) {
                            if (f) {
                                ans[i][l] = sum - cur;
                                ans[i][r] = cur;
                                f = false;
                            } else {
                                ans[i][l] = cur;
                                ans[i][r] = sum - cur;
                                f = true;
                            }
                            cur++;
                            l--;
                            r++;
                        }
                        cur += m / 2;
                    }
                    sum += 2 * m;
                }
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        out.print(ans[i][j] + " ");
                    }
                    out.println("");
                }
            } else {
                int cnt;
                for (int i = 1; i <= n; i++) {
                    if (i % 2 == 1) {
                        cnt = m * i;
                        for (int j = 1; j <= m; j++) {
                            out.print(cnt + " ");
                            cnt -= 2;
                            if (cnt <= m * (i - 1)) cnt = m * i - 1;
                        }
                    } else {
                        cnt = m * i - 1;
                        for (int j = 1; j <= m; j++) {
                            out.print(cnt + " ");
                            cnt -= 2;
                            if (cnt <= m * (i - 1)) cnt = m * i;
                        }
                    }
                    out.println("");
                }
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void print(String i) {
            out.print(i);
        }

        public void println(int i) {
            out.println(i);
        }

        public void println(String i) {
            out.println(i);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}