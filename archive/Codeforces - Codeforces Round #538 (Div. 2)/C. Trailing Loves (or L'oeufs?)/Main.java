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
        CTrailingLovesOrLoeufs solver = new CTrailingLovesOrLoeufs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTrailingLovesOrLoeufs {
        private static final long INFLL = (long) 9e18 + 7;
        boolean[] isPrime = new boolean[(int) 1e6 + 10];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long b = in.nextLong();
            sieve();
            long ans = INFLL;
            for (int i = 2; (long) i * i <= b; i++) {
                if (b % i == 0 && isPrime[i]) {
                    long total = 0;
                    long cur = i;
                    while (cur <= n) {
                        total += n / cur;
                        if (cur > n / i) break;
                        cur *= i;
                    }
                    int cnt = 0;
                    while (b % i == 0) {
                        b /= i;
                        cnt++;
                    }
                    ans = MaxMin.Min(ans, total / cnt);
                }
            }

            if (b != 1) {
                long total = 0;
                long cur = b;
                while (cur <= n) {
                    total += n / cur;
                    if (cur > n / b) break;
                    cur *= b;
                }
                ans = MaxMin.Min(ans, total);
            }

            out.println(ans);
        }

        private void sieve() {
            for (int i = 1; i <= (int) 1e6 + 5; i++) isPrime[i] = true;
            isPrime[0] = false;
            isPrime[1] = false;
            for (int i = 2; i <= (int) 1e6 + 5; i++)
                if (isPrime[i])
                    for (long j = (long) i * i; j <= (long) 1e6 + 5; j += i)
                        if (j < (long) 1e6 + 5)
                            isPrime[(int) j] = false;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}