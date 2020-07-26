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
        BGoodString solver = new BGoodString();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGoodString {
        private static final int INF = (int) 2e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                char[] a = in.nextCharArray(n, 1);
                int posO = -1;
                int posC = -1;

                for (int i = 1; i <= n; i++) {
                    if (a[i] == '>') {
                        posO = i;
                        break;
                    }
                }

                for (int i = n; i >= 1; i--) {
                    if (a[i] == '<') {
                        posC = i;
                        break;
                    }
                }
                int ans1 = INF, ans2 = INF;
                if (posO != -1) ans1 = posO - 1;
                if (posC != -1) ans2 = n - posC;
                out.println(MaxMin.Min(ans1, ans2));
            }
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