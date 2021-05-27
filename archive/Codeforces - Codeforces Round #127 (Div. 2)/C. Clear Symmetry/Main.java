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
        CClearSymmetry solver = new CClearSymmetry();
        solver.solve(1, in, out);
        out.close();
    }

    static class CClearSymmetry {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            if (n == 3) {
                out.println(5);
                return;
            }
            for (int i = 1; ; i += 2) {
                if (i * i / 2 + 1 < n) continue;
                if (n % 4 == 0) {
                    if (i * i / 2 >= n) {
                        out.println(i);
                        return;
                    }
                }
                if (n % 4 == 1) {
                    if (i * i / 2 + 1 >= n) {
                        out.println(i);
                        return;
                    }
                }
                if (n % 4 == 2) {
                    if ((i * i / 2 - 4) >= n - 2 && (i * i / 2 - 4) % 4 == 0) {
                        out.println(i);
                        return;
                    }
                }
                if (n % 4 == 3) {
                    if ((i * i / 2 - 4) >= n - 3 && (i * i / 2 - 4) % 4 == 0) {
                        out.println(i);
                        return;
                    }
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}