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
        DEqualizeThemAll solver = new DEqualizeThemAll();
        solver.solve(1, in, out);
        out.close();
    }

    static class DEqualizeThemAll {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] cnt = new int[200020];
            int max = 0;
            int pos = 0;
            for (int i = 1; i <= n; i++) {
                cnt[a[i]]++;
                if (cnt[a[i]] > max) {
                    pos = i;
                    max = cnt[a[i]];
                }
            }
            out.println(n - cnt[a[pos]]);
            for (int i = pos + 1; i <= n; i++) {
                if (a[i] != a[i - 1]) {
                    if (a[i] > a[i - 1])
                        out.println(2 + " " + i + " " + (i - 1));
                    else
                        out.println(1 + " " + i + " " + (i - 1));
                    a[i] = a[i - 1];
                }
            }
            for (int i = pos - 1; i >= 1; i--) {
                if (a[i] != a[i + 1]) {
                    if (a[i] > a[i + 1])
                        out.println(2 + " " + i + " " + (i + 1));
                    else
                        out.println(1 + " " + i + " " + (i + 1));
                    a[i] = a[i + 1];
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
}