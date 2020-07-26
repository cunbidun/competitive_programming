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
        ESuperheroBattle solver = new ESuperheroBattle();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESuperheroBattle {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long H = in.nextLong();
            long n = in.nextInt();
            long[] a = in.nextLongArray((int) n, 1);
            long tmp = H;
            for (int i = 1; i <= n; i++) {
                tmp += a[i];
                if (tmp <= 0) {
                    out.println(i);
                    return;
                }
            }
            long sum = 0;
            long maxDam = 0;
            for (int i = 1; i <= n; i++) {
                sum += a[i];
                maxDam = MaxMin.Min(sum, maxDam);
            }
            if (sum >= 0) {
                out.println(-1);
                return;
            }
            long time = Math.max((H + maxDam), 0) / (-sum) * n;
            long cur = (time / n) * (-sum);
            //    out.println(maxDam + " " + time + " " + cur);
            for (int j = 1; j <= maxDam / sum + 1; j++) {
                for (int i = 1; i <= n; i++) {
                    cur -= a[i];
                    time++;
                    if (cur >= H) {
                        out.println(time);
                        return;
                    }
                }
            }
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

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}