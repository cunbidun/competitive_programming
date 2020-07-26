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
        BEqualizePrices solver = new BEqualizePrices();
        solver.solve(1, in, out);
        out.close();
    }

    static class BEqualizePrices {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int q = in.nextInt();
            while (q-- > 0) {
                int n = in.nextInt();
                int k = in.nextInt();
                int[] a = in.nextIntArray(n, 1);
                int[] b = new int[n + 1];
                for (int i = 1; i <= n; i++) {
                    b[i] = a[i];
                    b[i] += k;
                }
                int ans = ArrayUtil.getMin(b, 1, n);
                boolean f = false;
                for (int i = 1; i <= n; i++) {
                    if (Math.abs(a[i] - ans) > k) {
                        out.println(-1);
                        f = true;
                        break;
                    }
                }
                if (!f) out.println(ans);
            }
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }

    static class ArrayUtil {
        public static int getMin(int[] array, int stIndex, int enIndex) {
            int min = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                min = MaxMin.Min(min, array[i]);
            }
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
}