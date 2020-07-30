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
        CSerejaAndBrackets solver = new CSerejaAndBrackets();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSerejaAndBrackets {
        private InputReader in;
        private PrintWriter out;
        private char[] a;
        private int add;
        private int curOpen;
        private int[] open;
        private int[] close;
        private int[] correct;
        private int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            String S = in.nextString();
            n = S.length();
            open = new int[n * 4];
            close = new int[n * 4];
            correct = new int[n * 4];

            a = StringAlgorithm.toCharArray(S, 1);
            buildTree(1, 1, n);

            int m = in.nextInt();
            while (m-- > 0)
                out.println(cal(in.nextInt(), in.nextInt()));
        }

        private void buildTree(int i, int l, int r) {
            if (l == r) {
                if (a[l] == '(') open[i] = 1;
                else close[i] = 1;
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
            int common = MaxMin.Min(open[i * 2], close[i * 2 + 1]);
            correct[i] = correct[i * 2] + correct[i * 2 + 1] + 2 * common;
            open[i] = open[i * 2] + open[i * 2 + 1] - common;
            close[i] = close[i * 2] + close[i * 2 + 1] - common;
        }

        private int cal(int l, int r) {
            add = 0;
            curOpen = 0;
            return get(1, 1, n, l, r) + add;
        }

        private int get(int i, int l, int r, int a, int b) {
            if (l > r || l > b || a > r) return 0;
            if (a <= l && r <= b) {
                add += MaxMin.Min(curOpen, close[i]) * 2;
                curOpen -= MaxMin.Min(curOpen, close[i]);
                curOpen += open[i];
                return correct[i];
            }
            int m = (l + r) >> 1;
            return get(i * 2, l, m, a, b) + get(i * 2 + 1, m + 1, r, a, b);
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

    static class StringAlgorithm {
        public static char[] toCharArray(String s, int stIndex) {
            char[] result = new char[s.length() + stIndex];
            for (int i = 0; i < s.length(); i++) {
                result[i + stIndex] = s.charAt(i);
            }
            return result;
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