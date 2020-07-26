import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CGourmetCat solver = new CGourmetCat();
        solver.solve(1, in, out);
        out.close();
    }

    static class CGourmetCat {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            long tmp = MaxMin.Min(a / 3, b / 2, c / 2);
            int res = 0;
            for (int i = 0; i <= 6; i++) {
                int cur = i;
                int cnt = 0;
                long tmpa = a - 3 * tmp;
                long tmpb = b - 2 * tmp;
                long tmpc = c - 2 * tmp;
                while (true) {
                    if (cur == 0 || cur == 1 || cur == 4) {
                        if (tmpa <= 0) break;
                        tmpa--;
                        cur++;
                        cur %= 7;
                        cnt++;
                    }
                    if (cur == 2 || cur == 6) {
                        if (tmpb <= 0) break;
                        tmpb--;
                        cur++;
                        cur %= 7;
                        cnt++;
                    }
                    if (cur == 3 || cur == 5) {
                        if (tmpc <= 0) break;
                        tmpc--;
                        cur++;
                        cur %= 7;
                        cnt++;
                    }
                }
                res = MaxMin.Max(res, cnt);
            }
            tmp *= 7;
            out.println(tmp + res);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y, T z) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            if (z.compareTo(min) < 0) min = z;
            return min;
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