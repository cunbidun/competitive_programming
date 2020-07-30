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
        EMedianString solver = new EMedianString();
        solver.solve(1, in, out);
        out.close();
    }

    static class EMedianString {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String tmp = new StringBuilder(in.nextString()).reverse().toString();
            int[] a = new int[n + 2];
            int[] b = new int[n + 2];
            int[] c = new int[n + 2];
            for (int i = 1; i <= n; i++) a[i] = tmp.charAt(i - 1) - 'a';
            tmp = new StringBuilder(in.nextString()).reverse().toString();
            for (int i = 1; i <= n; i++) b[i] = tmp.charAt(i - 1) - 'a';
            for (int i = 1; i <= n; i++) {
                c[i] += a[i] + b[i];
                if (c[i] >= 26) {
                    c[i] -= 26;
                    c[i + 1]++;
                }
            }
            int maxPos = n;
            if (c[n + 1] == 1) maxPos = n + 1;
            for (int i = maxPos; i >= 1; i--) {
                if (c[i] % 2 == 1) {
                    c[i] /= 2;
                    c[i - 1] += 26;
                } else c[i] /= 2;
            }

            for (int i = n; i >= 1; i--) {
                out.print((char) ('a' + c[i]));
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
}