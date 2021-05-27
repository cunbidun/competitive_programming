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
        Task1295C solver = new Task1295C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1295C {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int q = in.nextInt();
            while (q-- > 0) {
                String s = in.nextString();
                String t = in.nextString();
                int[][] next = new int[s.length() + 1][26];
                for (int j = 'a'; j <= 'z'; j++)
                    next[s.length()][j - 'a'] = s.length();
                for (int i = s.length() - 1; i >= 0; i--) {
                    for (int j = 'a'; j <= 'z'; j++)
                        next[i][j - 'a'] = next[i + 1][j - 'a'];
                    next[i][s.charAt(i) - 'a'] = i;
                }
                int pos = 0;
                int ans = 0;
                boolean f = false;
                for (int i = 0; i < t.length(); ) {
                    if (next[0][t.charAt(i) - 'a'] == s.length()) {
                        f = true;
                        break;
                    }

                    while (true) {
                        pos = next[pos][t.charAt(i) - 'a'];
                        if (pos == s.length()) break;
                        pos++;
                        i++;
                        if (i == t.length()) break;
                    }
                    pos = 0;
                    ans++;
                }
                if (f) {
                    out.println(-1);
                    continue;
                }
                out.println(ans);
            }
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
}