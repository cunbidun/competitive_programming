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
import java.util.ArrayList;
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
        Task1058D solver = new Task1058D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1058D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            if (((long) 2 * m * n) % k != 0) {
                out.println("NO");
                return;
            }
            ArrayList<Integer> l = new ArrayList<>();
            for (int i = 2; i <= Math.sqrt(k); i++) {
                if (k % i == 0) {
                    l.add(i);
                    if (k / i != i) l.add(k / i);
                }
            }
            if (k != 1) l.add(k);
            for (int i : l) {
                if ((2 * n) % i == 0 && m % (k / i) == 0) {
                    out.println("YES");
                    out.println(0 + " " + 0);
                    out.println((2 * n / i) + " " + 0);
                    out.println(0 + " " + (m / (k / i)));
                    return;
                }

                if ((2 * m) % i == 0 && n % (k / i) == 0) {
                    out.println("YES");
                    out.println(0 + " " + 0);
                    out.println((n / (k / i) + " " + 0));
                    out.println(0 + " " + (2 * m / i));
                    return;
                }
            }
            out.println("NO");
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}