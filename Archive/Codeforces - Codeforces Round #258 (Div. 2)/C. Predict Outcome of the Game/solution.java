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
        CPredictOutcomeOfTheGame solver = new CPredictOutcomeOfTheGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPredictOutcomeOfTheGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                long n = in.nextLong();
                long k = in.nextLong();
                long d1 = in.nextLong();
                long d2 = in.nextLong();
                long x, y, z;
                if (n % 3 != 0) {
                    out.println("no");
                    continue;
                }
                z = (k - d1 - d2 - d2) / 3;
                y = z + d2;
                x = y + d1;
                if (x + y + z == k && x >= 0 && y >= 0 && z >= 0) {
                    if (x <= n / 3 && y <= n / 3 && z <= n / 3) {
                        out.println("yes");
                        continue;
                    }
                }

                y = (k - d1 - d2) / 3;
                z = y + d2;
                x = y + d1;
                if (x + y + z == k && x >= 0 && y >= 0 && z >= 0) {
                    if (x <= n / 3 && y <= n / 3 && z <= n / 3) {
                        out.println("yes");
                        continue;
                    }
                }

                x = (k - d1 - d1 - d2) / 3;
                y = x + d1;
                z = y + d2;
                if (x + y + z == k && x >= 0 && y >= 0 && z >= 0) {
                    if (x <= n / 3 && y <= n / 3 && z <= n / 3) {
                        out.println("yes");
                        continue;
                    }
                }

                y = (k + d1 + d2) / 3;
                z = y - d2;
                x = y - d1;
                if (x + y + z == k && x >= 0 && y >= 0 && z >= 0) {
                    if (x <= n / 3 && y <= n / 3 && z <= n / 3) {
                        out.println("yes");
                        continue;
                    }
                }
                out.println("no");
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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