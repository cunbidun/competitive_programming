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
        CMagicShip solver = new CMagicShip();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMagicShip {
        private int cntU = 0;
        private int cntD = 0;
        private int cntL = 0;
        private int cntR = 0;
        private long x1;
        private long x2;
        private long y1;
        private long y2;
        private long n;
        private char[] a;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            x1 = in.nextLong();
            y1 = in.nextLong();
            x2 = in.nextLong();
            y2 = in.nextLong();
            n = in.nextLong();
            a = in.nextCharArray((int) n, 1);
            for (int i = 1; i <= (int) n; i++) {
                if (a[i] == 'U') cntU++;
                if (a[i] == 'D') cntD++;
                if (a[i] == 'L') cntL++;
                if (a[i] == 'R') cntR++;
            }

            long l = 0, r = 10000000000000000L;
            while (l != r) {
                if (l == r - 1) {
                    if (!check(l)) l = r;
                    break;
                }
                long m = (l + r) >> 1;
                if (check(m)) {
                    r = m;
                } else l = m + 1;
            }
            if (l == 10000000000000000L) {
                out.println(-1);
                return;
            }
            out.println(l);
        }

        private boolean check(long m) {
            long time = m / n;
            long tmpX = x1 + (cntR - cntL) * time;
            long tmpY = y1 + (cntU - cntD) * time;
            for (long i = 1; i <= m % n; i++) {
                if (a[(int) i] == 'U') tmpY++;
                if (a[(int) i] == 'D') tmpY--;
                if (a[(int) i] == 'L') tmpX--;
                if (a[(int) i] == 'R') tmpX++;
            }
            return (Math.abs(tmpX - x2) + Math.abs(tmpY - y2)) <= m;
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

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}