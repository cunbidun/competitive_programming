import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        CNekoDoesMaths solver = new CNekoDoesMaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNekoDoesMaths {
        private static final long INFLL = (long) 2e18 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            long a = in.nextInt();
            long b = in.nextInt();
            if (a > b) {
                long t = a;
                a = b;
                b = t;
            }
            long c = b - a;
            TreeSet<Long> divList = new TreeSet<>();
            for (int i = 1; i <= Math.sqrt(c); i++) {
                if (c % i == 0) {
                    divList.add((long) i);
                    divList.add(c / i);
                }
            }
            long min = INFLL;
            long pos = 0;
            for (Long div : divList) {
                long tmp = (a + div - 1) / div;
                long k = tmp * div - a;
                long tmpLCM = MathAlgorithm.lcm(a + k, b + k);
                if (tmp < min) {
                    min = tmp;
                    pos = k;
                }
            }
            out.println(pos);
        }

    }

    static class MathAlgorithm {
        public static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        public static long lcm(long a, long b) {
            return a / gcd(a, b) * b;
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