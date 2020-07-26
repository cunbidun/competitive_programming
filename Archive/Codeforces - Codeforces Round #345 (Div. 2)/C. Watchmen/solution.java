import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
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
        PrintWriter out = new PrintWriter(outputStream);
        CWatchmen solver = new CWatchmen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWatchmen {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            PairII[] a = new PairII[n + 1];
            PairII[] b = new PairII[n + 1];
            for (int i = 1; i <= n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                a[i] = new PairII(x, y);
                b[i] = new PairII(y, x);
            }
            Arrays.sort(a, 1, n + 1);
            Arrays.sort(b, 1, n + 1);
            long ans = 0, cnt = 1, cntE = 0;
            for (int i = 2; i <= n; i++) {
                if (a[i].first != a[i - 1].first) {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            for (int i = 2; i <= n; i++) {
                if (b[i].first != b[i - 1].first) {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            ans += cnt * (cnt - 1) / 2;
            cntE = 1;
            for (int i = 2; i <= n; i++) {
                if ((a[i].first == a[i - 1].first) && (a[i].second == a[i - 1].second)) cntE++;
                else {
                    ans -= cntE * (cntE - 1) / 2;
                    cntE = 1;
                }
            }
            ans -= cntE * (cntE - 1) / 2;
            out.println(ans);
        }

    }

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
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