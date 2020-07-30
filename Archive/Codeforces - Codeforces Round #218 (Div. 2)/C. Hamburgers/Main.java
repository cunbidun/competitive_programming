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
        CHamburgers solver = new CHamburgers();
        solver.solve(1, in, out);
        out.close();
    }

    static class CHamburgers {
        private long nb;
        private long ns;
        private long nc;
        private long r;
        private long pb;
        private long ps;
        private long pc;
        private long cntB = 0;
        private long cntS = 0;
        private long cntC = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String b = in.nextString();
            for (int i = 0; i < b.length(); i++) {
                if (b.charAt(i) == 'B') cntB++;
                if (b.charAt(i) == 'S') cntS++;
                if (b.charAt(i) == 'C') cntC++;
            }
            nb = in.nextLong();
            ns = in.nextLong();
            nc = in.nextLong();
            pb = in.nextLong();
            ps = in.nextLong();
            pc = in.nextLong();
            r = in.nextLong();
            long l = 0, r = (long) 1e15;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(r)) l = r;
                    break;
                }
                long m = (l + r) >> 1;
                if (ch(m)) l = m;
                else r = m - 1;
            }
            out.println(l);
        }

        private boolean ch(long m) {
            long nB = MaxMin.Max(0L, m * cntB - nb);
            long nS = MaxMin.Max(0L, m * cntS - ns);
            long nC = MaxMin.Max(0L, m * cntC - nc);
            return (nB * pb + nS * ps + nC * pc) <= r;
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }
}