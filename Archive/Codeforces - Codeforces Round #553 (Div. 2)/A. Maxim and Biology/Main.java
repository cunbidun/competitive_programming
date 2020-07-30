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
        AMaximAndBiology solver = new AMaximAndBiology();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMaximAndBiology {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            char[] a = in.nextCharArray(n, 1);
            int ans = INF;
            for (int i = 4; i <= n; i++) {
                char cur1 = a[i - 4 + 1];
                char cur2 = a[i - 4 + 2];
                char cur3 = a[i - 4 + 3];
                char cur4 = a[i - 4 + 4];
                int res = 0;
                res += MaxMin.Min(Math.abs(cur1 - 'A'), cur1 - 'A' + 'Z' - 'A' + 1, 'Z' - cur1 + 'A' - 'A' + 1);
                res += MaxMin.Min(Math.abs(cur2 - 'C'), cur2 - 'A' + 'Z' - 'C' + 1, 'Z' - cur2 + 'C' - 'A' + 1);
                res += MaxMin.Min(Math.abs(cur3 - 'T'), cur3 - 'A' + 'Z' - 'T' + 1, 'Z' - cur3 + 'T' - 'A' + 1);
                res += MaxMin.Min(Math.abs(cur4 - 'G'), cur4 - 'A' + 'Z' - 'G' + 1, 'Z' - cur4 + 'G' - 'A' + 1);
                ans = MaxMin.Min(ans, res);
            }
            out.println(ans);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}