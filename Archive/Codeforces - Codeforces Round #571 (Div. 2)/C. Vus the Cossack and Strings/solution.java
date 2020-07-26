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
        CVusTheCossackAndStrings solver = new CVusTheCossackAndStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVusTheCossackAndStrings {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            String a = in.nextString();
            String b = in.nextString();
            int cnt = StringUtils.count(b, '1');
            int[] s = new int[a.length() + 1];
            for (int i = 1; i <= a.length(); i++) {
                s[i] = s[i - 1];
                if (a.charAt(i - 1) == '1') s[i]++;
            }
            int ans = 0;
            for (int i = b.length(); i <= a.length(); i++) {
                if ((s[i] - s[i - b.length()] + cnt) % 2 == 0) {
                    ans++;
                }
            }
            out.println(ans);
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
}