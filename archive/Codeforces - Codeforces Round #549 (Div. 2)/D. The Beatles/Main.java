import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        DTheBeatles solver = new DTheBeatles();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTheBeatles {
        private static final long INFLL = (long) 9e15 + 7;
        private long n;
        private long k;
        private long numCity;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            long a = in.nextInt();
            long b = in.nextInt();
            numCity = n * k;
            long s1, s2;
            long S1, S2;
            if (k == a * 2 || a == 0) {
                S1 = S2 = 1 + a;
            } else {
                S1 = 1 + a;
                S2 = (1 - a + numCity);
            }
            ArrayList<Long> end = new ArrayList<>();
            if (k == b * 2 || b == 0) {
                s1 = s2 = 1 + b;
            } else {
                s1 = 1 + b;
                s2 = (1 - b + numCity);
            }
            for (int i = 1; i <= n; i++) {
                end.add(s1 + (i - 1) * k);
            }
            if (s1 != s2) {
                end.add(s2);
                for (int i = 1; i < n; i++) {
                    end.add((s2 + i * k) % (numCity));
                }
            }
            long max = 0;
            long min = INFLL;
            for (long i : end) {
                long tmp = cal(S1, i);
                if (tmp == 0) tmp = numCity;
                long cur = MathAlgorithm.gcd(numCity, tmp);
                max = MaxMin.Max(max, numCity / cur);
                min = MaxMin.Min(min, numCity / cur);
                tmp = cal(S2, i);
                if (tmp == 0) tmp = numCity;
                cur = MathAlgorithm.gcd(numCity, tmp);
                max = MaxMin.Max(max, numCity / cur);
                min = MaxMin.Min(min, numCity / cur);
            }
            out.println(min + " " + max);
        }

        private long cal(long st, long en) {
            if (st <= en) return en - st;
            else return numCity - st + en;
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class MathAlgorithm {
        public static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

    }
}