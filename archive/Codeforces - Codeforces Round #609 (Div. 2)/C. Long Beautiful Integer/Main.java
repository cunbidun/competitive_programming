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
        Task1269C solver = new Task1269C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1269C {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            String s = in.nextString();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = s.charAt(i - 1) - '0';
                b[i] = a[i];
            }

            out.println(n);

            for (int i = m + 1; i <= n; i++) b[i] = b[i - m];

            boolean done = true;
            for (int i = 1; i <= n; i++) {
                if (b[i] > a[i]) {
                    break;
                }
                if (b[i] < a[i]) {
                    done = false;
                    break;
                }
            }

            if (done) {
                for (int i = 1; i <= n; i++) {
                    out.print(b[i]);
                }
                return;
            }


            int pos = m;
            while (a[pos] == 9) {
                pos--;
                if (pos == 0) {
                    for (int i = 1; i <= n; i++) {
                        out.print(9);
                    }
                    return;
                }
            }

            a[pos]++;
            for (int i = pos + 1; i <= m; i++) a[i] = 0;

            for (int i = m + 1; i <= n; i++) a[i] = a[i - m];

            for (int i = 1; i <= n; i++) out.print(a[i]);
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

        public void print(int i) {
            out.print(i);
        }

        public void println(int i) {
            out.println(i);
        }

    }
}