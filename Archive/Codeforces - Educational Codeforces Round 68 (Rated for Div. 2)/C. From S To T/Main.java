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
        CFromSToT solver = new CFromSToT();
        solver.solve(1, in, out);
        out.close();
    }

    static class CFromSToT {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int q = in.nextInt();
            while (q-- > 0) {
                String s = in.nextString();
                String t = in.nextString();
                String p = in.nextString();
                if (!isSubSequence(s, t, s.length(), t.length())) {
                    out.println("NO");
                    continue;
                }
                boolean f = false;
                for (char i = 'a'; i <= 'z'; i++) {
                    int tmpT = StringUtils.count(t, i);
                    int tmpS = StringUtils.count(s, i);
                    int tmpP = StringUtils.count(p, i);
                    if (tmpT > tmpP + tmpS) {
                        f = true;
                        break;
                    }
                }
                if (f) out.println("NO");
                else out.println("YES");
            }
        }

        private boolean isSubSequence(String str1, String str2, int m, int n) {
            // Base Cases
            if (m == 0)
                return true;
            if (n == 0)
                return false;

            // If last characters of two strings are matching
            if (str1.charAt(m - 1) == str2.charAt(n - 1))
                return isSubSequence(str1, str2, m - 1, n - 1);

            // If last characters are not matching
            return isSubSequence(str1, str2, m, n - 1);
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

        public void println(String i) {
            out.println(i);
        }

    }

    static class StringUtils {
        public static int count(String S, int stIndex, int enIndex, char c) {
            int cnt = 0;
            for (int i = stIndex; i <= enIndex; i++) {
                if (S.charAt(i) == c) cnt++;
            }
            return cnt;
        }

        public static int count(String S, char c) {
            return count(S, 0, S.length() - 1, c);
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