import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        Task1178E solver = new Task1178E();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1178E {
        private InputReader in;
        private OutputWriter out;
        String s;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;

            s = in.nextString();
            int n = s.length();
            char[] a = StringUtils.toCharArray(s, 1);
            boolean[] used = new boolean[n + 1];
            Arrays.fill(used, true);
            int l = 1;
            int r = n;
            while (r - l + 1 >= 4) {
                if (a[l] == a[r]) {
                    used[l + 1] = false;
                    used[r - 1] = false;
                } else if (a[l] == a[r - 1]) {
                    used[l + 1] = false;
                    used[r] = false;
                } else if (a[l + 1] == a[r - 1]) {
                    used[l] = false;
                    used[r] = false;
                } else if (a[l + 1] == a[r]) {
                    used[l] = false;
                    used[r - 1] = false;
                }
                r -= 2;
                l += 2;
            }
            for (int i = l + 1; i <= r; i++) used[i] = false;

            for (int i = 1; i <= n; i++) {
                if (used[i]) out.print(a[i]);
            }
        }

    }

    static class StringUtils {
        public static char[] toCharArray(String s, int stIndex) {
            char[] result = new char[s.length() + stIndex];
            for (int i = 0; i < s.length(); i++) {
                result[i + stIndex] = s.charAt(i);
            }
            return result;
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

        public void print(char i) {
            out.print(i);
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
}