import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        ADiverseStrings solver = new ADiverseStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADiverseStrings {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                String s = in.nextString();
                int n = s.length();
                char[] a = StringAlgorithm.toCharArray(s, 1);
                Arrays.sort(a, 1, n + 1);
                boolean f = false;
                for (int i = 2; i <= n; i++) {
                    if (a[i] != (char) (a[i - 1] + 1)) {
                        out.println("No");
                        f = true;
                        break;
                    }
                }
                if (!f)
                    out.println("Yes");
            }
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