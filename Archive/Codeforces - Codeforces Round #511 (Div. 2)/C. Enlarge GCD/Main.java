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
        Task1047C solver = new Task1047C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1047C {
        private InputReader in;
        private OutputWriter out;
        private int numPrime = 0;
        private int MAX = (int) 1.5e7 + 1;
        private int[] primeList = new int[MAX];
        private int[] smallestPrime = new int[MAX];
        private int[] cnt = new int[MAX];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            for (int i = 2; i < MAX; i++) {
                if (smallestPrime[i] == 0) {
                    primeList[++numPrime] = i;
                    smallestPrime[i] = i;
                }
                for (int j = 1; j <= numPrime && primeList[j] <= smallestPrime[i] && primeList[j] * i < MAX; j++)
                    smallestPrime[primeList[j] * i] = primeList[j];
            }
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int gcd = 0;
            for (int i = 1; i <= n; i++) gcd = MathAlgorithm.gcd(gcd, a[i]);
            for (int i = 1; i <= n; i++) {
                int cur = a[i] / gcd;
                if (cur == 1) continue;
                while (cur != 1) {
                    int tmp = smallestPrime[cur];
                    cnt[tmp]++;
                    while (cur % tmp == 0) cur /= tmp;
                }
            }
            int ans = 100000000;
            for (int i = 1; i < MAX; i++) ans = MaxMin.Min(ans, n - cnt[i]);
            if (ans == n) out.println(-1);
            else out.println(ans);
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
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

        public void println(int i) {
            out.println(i);
        }

    }

    static class MathAlgorithm {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

    }
}