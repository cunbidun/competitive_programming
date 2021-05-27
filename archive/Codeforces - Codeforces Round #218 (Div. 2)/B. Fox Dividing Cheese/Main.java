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
        BFoxDividingCheese solver = new BFoxDividingCheese();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFoxDividingCheese {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();
            int cnt2A = 0, cnt3A = 0, cnt5A = 0, cnt2B = 0, cnt3B = 0, cnt5B = 0;
            while (a % 2 == 0) {
                cnt2A++;
                a /= 2;
            }
            while (a % 3 == 0) {
                cnt3A++;
                a /= 3;
            }
            while (a % 5 == 0) {
                cnt5A++;
                a /= 5;
            }

            while (b % 2 == 0) {
                cnt2B++;
                b /= 2;
            }
            while (b % 3 == 0) {
                cnt3B++;
                b /= 3;
            }
            while (b % 5 == 0) {
                cnt5B++;
                b /= 5;
            }
            if (a != b) {
                out.println(-1);
                return;
            } else out.println(Math.abs(cnt2A - cnt2B) + Math.abs(cnt3A - cnt3B) + Math.abs(cnt5A - cnt5B));
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